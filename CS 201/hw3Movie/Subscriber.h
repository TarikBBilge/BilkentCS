//
// Created by Tarik Berkan Bilge on 11/12/2022.
//

#ifndef HW3MOVIE_SUBSCRIBER_H
#define HW3MOVIE_SUBSCRIBER_H
#include "Movie.h"

using namespace std;

class Subscriber {
public:
    Subscriber( const int id = 0 );
    ~Subscriber();

    const int getId() const;
    void setId( const int id );

    const int getMovie() const;
    void setMovie( const int rented );

    void operator=(const Subscriber& right);

private:
    int subId;
    int rented;
    struct subNode{
        Movie movieId;
        subNode* nextSub;
    };
    subNode* head;
};

#endif //HW3MOVIE_SUBSCRIBER_H