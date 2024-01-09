package com.tarik.multiplayerdemo;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.utils.ScreenUtils;

import com.tarik.multiplayerdemo.sprites.Starship;

import io.socket.client.IO;
import io.socket.client.Socket;
import io.socket.emitter.Emitter;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.awt.*;
import java.awt.geom.AffineTransform;

import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.util.HashMap;

public class MultiplayerDemo extends ApplicationAdapter {
	private final float UPDATE_TIME = 1/60f;
	float timer;
	SpriteBatch batch;
	private Socket socket;
	String id;
	Starship player;
	Texture opponentShip;
	Texture serverShip;
	HashMap< String, Starship > opponentPlayers;
	
	@Override
	public void create () {
		batch = new SpriteBatch();
		opponentShip = new Texture( "playerShipRed.png" );

		serverShip = new Texture( "playerShipBlue.png" );
		opponentPlayers = new HashMap< String, Starship >();



		/*AffineTransform tx = AffineTransform.getScaleInstance(1, -1);
		tx.translate(0, -opponentShip.getHeight());
		AffineTransformOp op = new AffineTransformOp(tx,
				AffineTransformOp.TYPE_NEAREST_NEIGHBOR);
		opponentShip = op.filter( , null );*/

		connectSocket();
		configSocketEvents();
	}

	public void handleInput( float dt ){
		if( player != null ){
			if( Gdx.input.isKeyPressed( Input.Keys.LEFT ) ){
				player.setPosition( player.getX() + ( -200 * dt ), player.getY() );
			}
			else if( Gdx.input.isKeyPressed( Input.Keys.RIGHT ) ){
				player.setPosition( player.getX() + ( +200 * dt ), player.getY() );
			}
		}
	}

	public void updateServer( float dt ){
		timer += dt;

		if( timer >= UPDATE_TIME && player != null && player.hasMoved() ){
			JSONObject data = new JSONObject();
			try{
				data.put( "x", player.getX() );
				data.put( "y", player.getY() );
				socket.emit( "playerMoved", data );

			}catch( JSONException e ){
				Gdx.app.log( "Socket.IO", "Error sending update data" );
			}
		}
	}

	@Override
	public void render() {

		ScreenUtils.clear(1, 1, 1, 0);
		batch.begin();
		handleInput( Gdx.graphics.getDeltaTime() );
		updateServer( Gdx.graphics.getDeltaTime() );



		if( player != null ){
			player.draw( batch );
		}

		for( HashMap.Entry< String, Starship > entry: opponentPlayers.entrySet() ){
			entry.getValue().draw( batch );
		}

		batch.end();
	}

	/*public void render( float delta )
	{
		//Wipe Screen to black
		//Gdx.gl.glClearColor( Color.BLACK );
		Gdx.gl.glClear( GL20.GL_COLOR_BUFFER_BIT );

		//Left Half
		Gdx.gl.glViewport( 0,0,Gdx.graphics.getWidth()/2,Gdx.graphics.getHeight() );
		//Set up camera with viewport in mind
		//draw( delta );

		//Right Half
		Gdx.gl.glViewport( Gdx.graphics.getWidth()/2,0,Gdx.graphics.getWidth()/2,Gdx.graphics.getHeight() );
		//Set up camera again with other viewport in mind
		draw( delta );
	}*/

	
	@Override
	public void dispose () {
		super.dispose();
		opponentShip.dispose();
		serverShip.dispose();
	}

	public void connectSocket(){
		try{
			socket = IO.socket( "http://localhost:8080" );
			socket.connect();
		}catch( Exception e ){
			System.out.println( e );
		}
	}

	public void configSocketEvents(){
		socket.on(Socket.EVENT_CONNECT, new Emitter.Listener() {
			@Override
			public void call(Object... args) {
				Gdx.app.log( "SocketIO", "Connected" );
				player = new Starship( serverShip );
			}
		}).on("SocketID", new Emitter.Listener() {
			@Override
			public void call(Object... args) {
				JSONObject data = (JSONObject) args[ 0 ];
				try {
					id = data.getString("id" );
					Gdx.app.log("SocketIO", "My ID: " + id );
				}catch( JSONException e ){
					Gdx.app.log( "SocketIO" ,"Error getting ID" );
				}
			}
		}).on("newPlayer", new Emitter.Listener() {
			@Override
			public void call(Object... args) {
				JSONObject data = (JSONObject) args[ 0 ];
				try {
					String playerId = data.getString("id" );
					Gdx.app.log("SocketIO", "New Player Connect: " + id );
					opponentPlayers.put( playerId, new Starship( opponentShip ) );
				}catch( JSONException e ){
					Gdx.app.log( "SocketIO" ,"Error getting new player ID" );
				}
			}
		}).on("playerDisconnected", new Emitter.Listener() {
			@Override
			public void call(Object... args) {
				JSONObject data = (JSONObject) args[ 0 ];
				try {
					String id = data.getString("id" );
					opponentPlayers.remove( id );
				}catch( JSONException e ){
					Gdx.app.log( "SocketIO" ,"Error getting new player ID" );
				}
			}
		}).on("playerMoved", new Emitter.Listener() {
			@Override
			public void call(Object... args) {
				JSONObject data = (JSONObject) args[ 0 ];
				try {
					String playerId = data.getString( "id" );
					Double x = data.getDouble( "x" );
					Double y = data.getDouble( "y" );

					if( opponentPlayers.get( playerId ) != null ){
						opponentPlayers.get( playerId ).setPosition( x.floatValue() ,
								Gdx.graphics.getHeight() - opponentShip.getHeight() );
					}

				}catch( JSONException e ){
				}
			}
		}).on("getPlayers", new Emitter.Listener() {
			@Override
			public void call(Object... args) {
				JSONArray objects = (JSONArray) args[ 0 ];
				try{
					for( int i = 0; i < objects.length(); i++ ){
						Starship rivalPlayer = new Starship( opponentShip );
						Vector2 position = new Vector2();
						position.x = ( (Double) objects.getJSONObject( i ).getDouble( "x" ) ).floatValue();
						position.y = ( (Double) objects.getJSONObject( i ).getDouble( "y" ) ).floatValue();
						rivalPlayer.setPosition( position.x, position.y );

						opponentPlayers.put( objects.getJSONObject( i ).getString( "id" ), rivalPlayer );
					}
				}catch( JSONException e ){
				}
			}
		});
	}
}
