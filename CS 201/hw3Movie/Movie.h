//
// Created by Tarik Berkan Bilge on 11/12/2022.
//

#ifndef HW3MOVIE_MOVIE_H
#define HW3MOVIE_MOVIE_H

class Movie {
public:
    Movie( const int id = 0 );
    ~Movie();

    const int getId() const;
    void setId( const int id );

    const int getCopies() const;
    void setCopies( const int copyCount );

    const int getSub() const;
    void setSub( const int subId );

    void operator=(const Movie& right);

private:
    int movieId;
    int copy;
    int subId;
};

#endif //HW3MOVIE_MOVIE_H