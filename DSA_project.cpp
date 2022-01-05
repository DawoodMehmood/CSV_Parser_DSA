#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;
class Movie;          // for storing data about the movie - all 28 attributes
class MovieNode;      // node for linked list of movies
class MovieList;      // to traverse over the linked list of movies - chain of movie nodes
class ActorsInMovie;  // for pointing to all the actors of a certain movie
class Actor;          // for storing data about the actor - name and likes
class ActorNode;      // node for linked list of actors
class ActorList;      // to traverse over the linked list of actors - chain of actor nodes
class MoviesActedIn;  // for pointing to all the movies of a certain actor
class Director;       // for storing data about the director - name and likes
class DirectorNode;   // node for linked list of directors
class DirectorList;   // to traverse over the linked list of directors - chain of director nodes
class MoviesDirected; // for pointing to all the movies of a certain director
class GenreNode;      // node for storing type of genre and all the movies related to it through genre movie node
class GenreMovieNode; // node for pointing to movies under genre list
class GenreList;      // to traverse over the linked list of genre related movies - chain of genre nodes
class YearWiseNode;   // node for pointing to movies under each year
class YearWiseList;   // to traverse over the array of year related movies - chain of year wise nodes
class RatingWiseNode; // node for pointing to movies under each rating
class RatingWiseList; // to traverse over the linked list of rating related movies - chain of rating wise nodes

void parser(MovieList *mList, ActorList *aList, DirectorList *dList, GenreList *gList, YearWiseList *yList, RatingWiseList *rList);
void AddGenre(GenreList *gList, MovieNode *movie, string genre);
void searchActor(ActorList *aList, YearWiseList *yList, string name);
void searchDirector(DirectorList *dList, string name);
void moviesOfDirectorOfGivenGenre(GenreList *gList, string genre);
void searchMovie(MovieList *mList, string movie_name);
void searchMoviesWithYear(YearWiseList *yList, int year);
void moviesYearWise(YearWiseList *yList);
void searchCoActorsOfActor(ActorList *aList, string actor_name);
void searchUniqueCoActors(ActorList *aList, MovieList *mList, string actor_name);
void searchCoActorsOfCoActors(ActorList *aList, string actor_name);
void checkIfCoActors(ActorList *aList, MovieList *mList, string actor_a, string actor_b);
void searchMoviesWithGenre(RatingWiseList *rList, string Genre);
void moviesRatingWise(RatingWiseList *rList);

class Movie
{
public:
    string movie_title;
    vector<string> genre{};
    unsigned short int title_year;
    float imdb_score;
    DirectorNode *director;
    unsigned short int num_critic_for_reviews;
    unsigned short int duration;
    ActorsInMovie *pstart_actor;
    unsigned long int gross;
    unsigned int num_voted_users;
    unsigned int cast_total_facebook_likes;
    unsigned short int facenumber_in_poster;
    vector<string> plot_keywords{};
    string movie_imdb_link;
    unsigned short int num_user_for_reviews;
    string language;
    string country;
    string content_rating;
    unsigned long int budget;
    float aspect_ratio;
    unsigned int movie_facebook_likes;
    string color;
};

class MovieNode
{
public:
    Movie data;
    MovieNode *next;
};

class MovieList
{
public:
    MovieNode *start = NULL;    //as head of movie node linked list
    MovieNode *end = NULL;      //as tail of movie node linked list
    MovieNode *currNode = NULL; //pointer to current node for traversal
    MovieNode *prevNode = NULL; //pointer to previous node of current node for traversal

    //function to search if list of movies is empty
    bool isMovieListEmpty()
    {
        return start == NULL;
    }

    //function to search if a movie name exits in the movie list
    bool search(string name)
    {
        currNode = start;
        prevNode = NULL;

        if (isMovieListEmpty())
            return false;

        //substr - to ignore the special character at the end of each movie name
        while (currNode != NULL && currNode->data.movie_title.substr(0, currNode->data.movie_title.length() - 2) != name)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        if (currNode == NULL)
        {
            return false;
        }
        else
            return true;
    }
};

class Actor
{
public:
    string actor_name;
    unsigned int actor_facebook_likes = 0;
};

class ActorNode
{
public:
    Actor data;
    ActorNode *next;
    MoviesActedIn *start;
};

class ActorsInMovie
{
public:
    ActorNode *pdata;
    ActorsInMovie *next;
};

class ActorList
{
public:
    ActorNode *start = NULL;    //as head of movie node linked list
    ActorNode *end = NULL;      //as tail of movie node linked list
    ActorNode *currNode = NULL; //pointer to current node for traversal
    ActorNode *prevNode = NULL; //pointer to previous node of current node for traversal

    bool isActorListEmpty()
    {
        return start == NULL;
    }

    bool search(string name)
    {
        currNode = start;
        prevNode = NULL;
        if (isActorListEmpty())
            return false;

        while (currNode != NULL && currNode->data.actor_name != name)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        if (currNode == NULL)
        {
            return false;
        }
        else
            return true;
    }
};

class MoviesActedIn
{
public:
    MovieNode *pdata;
    MoviesActedIn *next;
};

class Director
{
public:
    string director_name;
    unsigned int director_facebook_likes;
};

class DirectorNode
{
public:
    Director data;
    DirectorNode *next;
    MoviesDirected *start;
};

class DirectorList
{
public:
    DirectorNode *start = NULL;    //as head of movie node linked list
    DirectorNode *end = NULL;      //as tail of movie node linked list
    DirectorNode *currNode = NULL; //pointer to current node for traversal
    DirectorNode *prevNode = NULL; //pointer to previous node of current node for traversal

    bool isDirectorListEmpty()
    {
        return start == NULL;
    }

    bool search(string name)
    {
        currNode = start;
        prevNode = NULL;
        if (isDirectorListEmpty())
            return false;
        while (currNode != NULL && currNode->data.director_name != name)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        if (currNode == NULL)
        {
            return false;
        }
        else
            return true;
    }
};

class MoviesDirected
{
public:
    MovieNode *pdata;
    MoviesDirected *next;
};

class GenreMovieNode
{
public:
    MovieNode *pdata;
    GenreMovieNode *next;
};

class GenreNode
{
public:
    string genre_type;
    GenreNode *next;
    GenreMovieNode *start;
};

class GenreList
{
public:
    GenreNode *start;    //as head of movie node linked list
    GenreNode *end;      //as tail of movie node linked list
    GenreNode *currNode; //pointer to current node for traversal
    GenreNode *prevNode; //pointer to previous node of current node for traversal

    //default constructor - setting 3 pointers to NULL
    GenreList()
    {
        start = NULL;
        end = NULL;
        prevNode = NULL;
    }

    bool isGenreEmpty()
    {
        return start == NULL;
    }

    bool search(string name)
    {
        {
            currNode = start;
            prevNode = NULL;
            if (isGenreEmpty())
                return false;
            while (currNode != NULL && currNode->genre_type != name)
            {
                prevNode = currNode;
                currNode = currNode->next;
            }
            if (currNode == NULL)
            {
                return false;
            }
            else
                return true;
        }
    }
};

class YearWiseNode
{
public:
    MovieNode *pdata;
    YearWiseNode *next;
};

class YearWiseList
{
public:
    YearWiseNode *pYearWise[102]; //to store movies of 101 years
    int minYear = 1916;           //as least year of a movie in file is 1916
    int maxNoOfYears = 102;       //as years of movies range from 1916 to 2016

    //default constructor - setting all the places to NULL
    YearWiseList()
    {
        for (int i = 0; i < 102; i++)
        {
            pYearWise[i] = NULL;
        }
    }
};

class RatingMovieNode
{
public:
    MovieNode *pdata;
    RatingMovieNode *next;
};

class RatingWiseNode
{
public:
    float rating;
    RatingMovieNode *start;
    RatingWiseNode *next;
};

class RatingWiseList
{
public:
    RatingWiseNode *start;    //as head of movie node linked list
    RatingWiseNode *end;      //as tail of movie node linked list
    RatingWiseNode *currNode; //pointer to current node for traversal
    RatingWiseNode *prevNode; //pointer to previous node of current node for traversal

    RatingWiseList()
    {
        start = NULL;
        end = NULL;
        prevNode = NULL;
        currNode = NULL;
    }

    bool isRatingWiseEmpty()
    {
        return start == NULL;
    }

    void search(float Rating)
    {
        currNode = start;
        prevNode = NULL;
        if (!isRatingWiseEmpty())
        {
            while (currNode != NULL && currNode->rating > Rating)
            {
                prevNode = currNode;
                currNode = currNode->next;
            }
        }
    }

    void insertNodeRatingWise(float Rating)
    {
        search(Rating);
        RatingWiseNode *newnode = new RatingWiseNode();
        newnode->rating = Rating;
        newnode->next = NULL;
        if (prevNode == NULL)
        {
            if (isRatingWiseEmpty())
            {
                start = newnode;
                end = newnode;
            }
            else
            {
                newnode->next = start;
                start = newnode;
            }
        }
        else
        {
            newnode->next = prevNode->next;
            prevNode->next = newnode;
            if (prevNode == end)
                end = newnode;
        }
    }
};

// Parser function gets all the data from the .csv file and feed it in all of the respective linked lists
void parser(MovieList *mList, ActorList *aList, DirectorList *dList, GenreList *gList, YearWiseList *yList, RatingWiseList *rList)
{
    ifstream fileStream("IMDB_Top5000-SEECS.csv");
    if (!(fileStream.is_open()))
    {
        cout << "File cannot be opened\n"
             << endl;
        return;
    }

    string row;
    string tempstring = "";
    string temp2string = "";
    int i = 0;
    int year = 0;
    getline(fileStream, row);

    //reading the file and storing in the same sequence of attributes as in file based on comma separation
    while (getline(fileStream, row))
    {
        MovieNode *movie = new MovieNode(); //creating a movieNode object to store all the data in respective attributes
        stringstream ss(row);               //converting a row of .csv file into a stream of strings

        //storing movie title
        getline(ss, movie->data.movie_title, ',');

        // Fetching genre - starts
        string genre, temp; //variables to store the strings coming from stream
        getline(ss, temp, ',');
        int j = 0;

        //looping through the string as there are more than one genres of a movie
        do
        {
            //traversing string upto divider line or vertical slash as it separates the different genres
            if (temp[j] == '|')
            {
                //storing in the vector class through its push_back function so every coming element will be added to last
                movie->data.genre.push_back(genre);

                //also storing the genre in its separate list for genreWise traversal later on
                AddGenre(gList, movie, genre);
                genre = ""; //initializing the variable back to empty for next iteration
                j++;
            }
            genre += temp[j]; //if no vertical slash untill then storing it in the genre variable
            j++;
        } while (temp[j] != '\0');

        movie->data.genre.push_back(genre);
        AddGenre(gList, movie, genre);
        // Fetching genre - ends

        // Fetching title_year and converting into integer - starts
        getline(ss, tempstring, ',');
        int index;
        //if year column is empty then storing year as 0 for the current movie
        if (tempstring.empty() || tempstring == "0")
        {
            year = 0;
            index = 101; //setting the index to 101 from 102 because of empty year
        }
        else
        {
            year = stoi(tempstring);       //converting string year into integer through 'stoi'
            index = year - yList->minYear; //setting the index by subracting current year from minimum year 1916
        }

        //storing movie year after conversion to integer
        movie->data.title_year = year;

        //year will also be stored in YearWiseList as YearWiseNode for separate traversal required for a function
        YearWiseNode *movie_toinsert = new YearWiseNode();
        movie_toinsert->pdata = movie;
        movie_toinsert->next = NULL;
        if (yList->pYearWise[index] == NULL)
            yList->pYearWise[index] = movie_toinsert;
        else
        {
            YearWiseNode *temp_prevNode = yList->pYearWise[index];
            while (temp_prevNode->next != NULL)
            {
                temp_prevNode = temp_prevNode->next;
            }
            temp_prevNode->next = movie_toinsert;
        }
        // ends

        // Fetching imdb_score and converting into float - stars
        getline(ss, tempstring, ',');
        float rating;
        if (tempstring.empty())
        {
            rating = 0.0;
            //r_index = rList->maxNoOfYears;
        }
        else
        {
            rating = stof(tempstring);
        }
        movie->data.imdb_score = rating;
        rList->insertNodeRatingWise(rating);
        rList->search(rating);
        RatingMovieNode *temp_rating_movie = new RatingMovieNode();
        temp_rating_movie->pdata = movie;
        temp_rating_movie->next = NULL;
        if (rList->currNode->start == NULL)
        {
            rList->currNode->start = temp_rating_movie;
        }
        else
        {
            RatingMovieNode *prevNode = rList->currNode->start;
            while (prevNode->next != NULL)
            {
                prevNode = prevNode->next;
            }
            prevNode->next = temp_rating_movie;
        }
        // ends

        //Fetching director name and storing it in directors list and pointing that to movie list
        getline(ss, tempstring, ',');  // director name
        getline(ss, temp2string, ','); // facebook likes
        if (!tempstring.empty())
        {
            MoviesDirected *directedmovie = new MoviesDirected();
            directedmovie->pdata = movie;
            directedmovie->next = NULL;
            if (!dList->search(tempstring))
            {
                DirectorNode *dNode = new DirectorNode();
                dNode->data.director_name = tempstring;
                // Fetching director_fb_likes and converting into integer
                if (temp2string.empty())
                    dNode->data.director_facebook_likes = 0;
                else
                    dNode->data.director_facebook_likes = stoi(temp2string);
                movie->data.director = dNode; // pointing movie node's director node to director node.
                dNode->start = directedmovie;
                if (dList->isDirectorListEmpty())
                {
                    dList->start = dNode;
                    dList->end = dNode;
                }
                else
                {
                    dList->end->next = dNode;
                    dList->end = dNode;
                }
            }
            else
            {
                movie->data.director = dList->currNode;
                MoviesDirected *prevNode = new MoviesDirected();
                prevNode = dList->currNode->start;
                while (prevNode->next != NULL)
                {
                    prevNode = prevNode->next;
                }
                prevNode->next = directedmovie;
            }
        }
        // ends

        // Fetching num_critics and converting into integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.num_critic_for_reviews = 0;
        else
            movie->data.num_critic_for_reviews = stoi(tempstring);
        // ends

        // Fetching duration and converting into integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.duration = 0;
        else
            movie->data.duration = stoi(tempstring);
        // ends

        // Fetching actors, storing them in array list and doing required pointing.
        for (int i = 0; i < 3; ++i)
        {
            getline(ss, tempstring, ',');  // actor name
            getline(ss, temp2string, ','); // facebook likes
            if (tempstring.empty())
                continue; // if no actor move to next loop

            // Runs if actor does not exist in list.
            if (!aList->search(tempstring))
            {
                // Creating an actor node and assiging it data.
                ActorNode *aNode = new ActorNode();
                aNode->data.actor_name = tempstring;
                if (temp2string.empty())
                    aNode->data.actor_facebook_likes = 0;
                else
                    aNode->data.actor_facebook_likes = stoi(temp2string);

                // If a new actor is created, it will be its first movie.
                // Movie added to actor's MovieActedIn list
                MoviesActedIn *movie_to_insert = new MoviesActedIn();
                movie_to_insert->pdata = movie;
                movie_to_insert->next = NULL;
                aNode->start = movie_to_insert;
                // new node created in Movie's ActorsInMovie list and actor is added.
                ActorsInMovie *actor_to_insert = new ActorsInMovie();
                actor_to_insert->pdata = aNode;
                actor_to_insert->next = NULL;
                // If Movie's ActorInMovie list is empty, add actor to first node
                if (movie->data.pstart_actor == NULL)
                {
                    movie->data.pstart_actor = actor_to_insert;
                }
                // Otherwise add it to the end.
                else
                {
                    ActorsInMovie *prevNode = new ActorsInMovie();
                    prevNode = movie->data.pstart_actor;
                    while (prevNode->next != NULL)
                    {
                        prevNode = prevNode->next;
                    }
                    prevNode->next = actor_to_insert;
                }

                // Finally add created actor node to Actor List.
                if (aList->isActorListEmpty())
                {
                    aList->start = aNode;
                    aList->end = aNode;
                }
                else
                {
                    aList->end->next = aNode;
                    aList->end = aNode;
                }
            }

            // If actor already exists.
            else
            {
                // Add Movie to the end of actor's MoviesActedIn list.
                MoviesActedIn *movie_to_insert = new MoviesActedIn;
                MoviesActedIn *prevNode = new MoviesActedIn;
                movie_to_insert->pdata = movie;
                movie_to_insert->next = NULL;
                prevNode = aList->currNode->start;
                while (prevNode->next != NULL)
                {
                    prevNode = prevNode->next;
                }
                prevNode->next = movie_to_insert;

                // Create a node in ActorsInMovie list which points to the found actor.
                ActorsInMovie *actor_to_insert = new ActorsInMovie();
                actor_to_insert->pdata = aList->currNode;
                actor_to_insert->next = NULL;

                // If this actor is the first actor of ActorsInMovie list for this movie
                if (movie->data.pstart_actor == NULL)
                {
                    movie->data.pstart_actor = actor_to_insert;
                }

                // Otherwise add this to the end of ActorsInMovie list for this movie.
                else
                {
                    ActorsInMovie *prevNode = new ActorsInMovie();
                    prevNode = movie->data.pstart_actor;
                    while (prevNode->next != NULL)
                    {
                        prevNode = prevNode->next;
                    }
                    prevNode->next = actor_to_insert;
                }

                // Reintializing strings for next loop.
                temp2string = "";
                tempstring = "";
            }
        }

        // Fetching gross and converting into float
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.gross = 0;
        else
            movie->data.gross = stoll(tempstring);
        // ends

        // Fetching num_voted_users and converting into integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.num_voted_users = 0;
        else
            movie->data.num_voted_users = stoi(tempstring);
        // ends

        // Fetching cast_total_facebook_likes and converting in to integer
        getline(ss, tempstring, ',');

        if (tempstring.empty())
            movie->data.cast_total_facebook_likes = 0;
        else
            movie->data.cast_total_facebook_likes = stoi(tempstring);
        // ends

        // Fetching facenumber_in_poster and converting in to the integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.facenumber_in_poster = 0;
        else
            movie->data.facenumber_in_poster = stoi(tempstring);
        // ends

        // Fetching keyword and storing them in plot_keyword vector
        tempstring = "";
        string keyword;
        getline(ss, tempstring, ',');
        int x = 0;
        do
        {
            if (tempstring[x] == '|')
            {
                movie->data.plot_keywords.push_back(keyword);
                keyword = "";
                x++;
            }
            keyword += tempstring[x];
            x++;
        } while (tempstring[x] != '\0');
        movie->data.plot_keywords.push_back(keyword);
        // ends

        // Fetching imdb_link
        getline(ss, movie->data.movie_imdb_link, ',');

        // Fetching numuser and converting in to integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.num_user_for_reviews = 0;
        else
            movie->data.num_user_for_reviews = stoi(tempstring);
        // ends

        // Fetching langauge
        getline(ss, movie->data.language, ',');

        // Fetching country
        getline(ss, movie->data.country, ',');

        // Fetching content_rating
        getline(ss, movie->data.content_rating, ',');

        // Fetching budget and converting in to integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.budget = 0;
        else
            movie->data.budget = stoll(tempstring);
        // ends

        // Fetching aspect_ratio and converting into float
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.aspect_ratio = 0;
        else
            movie->data.aspect_ratio = stof(tempstring);
        // ends

        // Fetching movie_facebook_likes and converting in to integer
        getline(ss, tempstring, ',');
        if (tempstring.empty())
            movie->data.movie_facebook_likes = 0;
        else
            movie->data.movie_facebook_likes = stoi(tempstring);
        // ends

        // Fetching color
        getline(ss, movie->data.color, ',');

        // Adding Movie Node to MovieList.
        if (mList->isMovieListEmpty())
        {
            mList->start = movie;
            mList->end = movie;
        }
        else
        {
            mList->end->next = movie;
            mList->end = movie;
        }
        i++;
    }
}

// Add genre is used by parser to add genre type to genre list
void AddGenre(GenreList *gList, MovieNode *movie, string genre)
{
    GenreMovieNode *pgenre = new GenreMovieNode();
    pgenre->pdata = movie;
    pgenre->next = NULL;
    if (!gList->search(genre))
    {
        GenreNode *pgenre_node_toinsert = new GenreNode();
        pgenre_node_toinsert->genre_type = genre;
        pgenre_node_toinsert->start = pgenre;
        if (gList->isGenreEmpty())
        {
            gList->start = pgenre_node_toinsert;
            gList->end = pgenre_node_toinsert;
        }
        else
        {
            gList->end->next = pgenre_node_toinsert;
            gList->end = pgenre_node_toinsert;
        }
    }
    else
    {
        GenreMovieNode *prevNode = new GenreMovieNode();
        prevNode = gList->currNode->start;
        while (prevNode->next != NULL)
        {
            prevNode = prevNode->next;
        }
        prevNode->next = pgenre;
    }
}


//----------------------------Menu Functions---------------------------

// searches for the given actor and print all of his/her movies in chronoligcal order
void searchActor(ActorList *aList, YearWiseList *yList, string name)
{
    if (!aList->search(name))
    {
        cout << "Actor not found." << endl;
    }
    else
    {
        YearWiseNode *temp_year_node;
        ActorsInMovie *temp_actor;
        int count = 0;
        for (int i = 0; i < yList->maxNoOfYears; i++)
        {
            temp_year_node = yList->pYearWise[i];
            while (temp_year_node != NULL)
            {
                temp_actor = temp_year_node->pdata->data.pstart_actor;
                while (temp_actor != NULL)
                {
                    if (temp_actor->pdata->data.actor_name == name)
                    {
                        cout << temp_year_node->pdata->data.title_year << " ";
                        cout << temp_year_node->pdata->data.movie_title.substr(0, temp_year_node->pdata->data.movie_title.size() - 2);
                        cout << endl;
                        count++;
                    }
                    temp_actor = temp_actor->next;
                }
                temp_year_node = temp_year_node->next;
            }
        }
        cout << "\n Total movies acted in: " << count << endl;
    }
}

// Print all movies of a given director
void searchDirector(DirectorList *dList, string name)
{
    if (!dList->search(name))
    {
        cout << "Director not found." << endl;
    }
    else
    {
        DirectorNode *temp_director = dList->currNode;
        MoviesDirected *temp_movies_directed = temp_director->start;
        cout << "The movies directed by " << temp_director->data.director_name << " are:" << endl;
        while (temp_movies_directed != NULL)
        {
            cout << temp_movies_directed->pdata->data.movie_title.substr(0,temp_movies_directed->pdata->data.movie_title.length() - 2)
                 << endl;
            temp_movies_directed = temp_movies_directed->next;
        }
    }
}

// Print director names of all movies of given genre
void moviesOfDirectorOfGivenGenre(GenreList *gList, string genre)
{
    if (!gList->search(genre))
    {
        cout << "No Such Genre";
    }
    else
    {
        set<string> director_list;
        GenreMovieNode *temp_genre_movie = gList->currNode->start;
        while (temp_genre_movie != NULL)
        {
            string temp = temp_genre_movie->pdata->data.director->data.director_name;
            director_list.insert(temp);
            temp_genre_movie = temp_genre_movie->next;
        }
        // Creating a iterator pointing to start of set
        set<string>::iterator it = director_list.begin();
        while (it != director_list.end())
        {
            // Print the element
            cout << (*it) << endl;
            //Increment the iterator
            it++;
        }
    }
}

// Prints details of given movie
void searchMovie(MovieList *mList, string movie_name)
{
    if (!mList->search(movie_name))
    {
        cout << "Movie Not Found";
    }
    else
    {
        MovieNode *temp_movie = mList->currNode;
        cout << "Movie Name: " << movie_name << endl;
        cout << "Release Year: " << temp_movie->data.title_year << endl;
        cout << "Directed By: " << temp_movie->data.director->data.director_name << endl;
        cout << "Star Role: " << temp_movie->data.pstart_actor->pdata->data.actor_name << endl;
        cout << "IMDB Rating: " << temp_movie->data.imdb_score << endl;
        cout << "Gross: " << temp_movie->data.gross << endl;
        cout << "Language: " << temp_movie->data.language << endl;
        cout << "Genre: " << temp_movie->data.genre[0] << endl;
    }
}

// Prints all movies in a given year.
void searchMoviesWithYear(YearWiseList *yList, int year)
{
    if (year < 1916 || year > 2016) // min and max years in database
    {
        cout << "The record is only from 1916 to 2016" << endl;
    }
    else
    {
        if (yList->pYearWise[year - yList->minYear] == NULL)
        {
            cout << "No Movies found in given Year" << endl;
        }
        else
        {
            YearWiseNode *temp_movie_node = new YearWiseNode();
            temp_movie_node = yList->pYearWise[year - yList->minYear];
            while (temp_movie_node != NULL)
            {
                cout << temp_movie_node->pdata->data.movie_title.substr(0, temp_movie_node->pdata->data.movie_title.length() - 2) << endl;
                temp_movie_node = temp_movie_node->next;
            }
        }
    }
}

// Print movies in year wise order (ascending)
void moviesYearWise(YearWiseList *yList)
{
    int size = yList->maxNoOfYears;
    for (int i = 0; i < size; i++)
    {
        YearWiseNode *temp_yearwise_movie = yList->pYearWise[i];
        if (i == size - 1)
        {
            cout << "Following Movies do not have years in database." << endl;
        }
        else
            cout << "\nYEAR " << i + yList->minYear << endl;
        while (temp_yearwise_movie != NULL)
        {
            cout << temp_yearwise_movie->pdata->data.movie_title.substr(0, temp_yearwise_movie->pdata->data.movie_title.length() - 2) << "  ";
            cout << temp_yearwise_movie->pdata->data.title_year << endl;
            temp_yearwise_movie = temp_yearwise_movie->next;
        }
    }
}

// Searches for coactors of given actor along with movie names they have worked in
void searchCoActorsOfActor(ActorList *aList, string actor_name)
{

    if (!aList->search(actor_name))
    {
        cout << "Actor not Found. Try Again!";
    }
    else
    {
        ActorNode *actor = aList->currNode;
        MoviesActedIn *temp_movie_acted_in = actor->start;
        while (temp_movie_acted_in != NULL)
        {
            ActorsInMovie *temp_actor_in_movie = temp_movie_acted_in->pdata->data.pstart_actor;
            string movie_title = temp_movie_acted_in->pdata->data.movie_title.substr(0,(temp_movie_acted_in->pdata->data.movie_title.length()) - 2);
            cout << "\n"
                 << movie_title << endl;
            while (temp_actor_in_movie != NULL)
            {
                if (temp_actor_in_movie->pdata->data.actor_name != actor_name)
                    cout << temp_actor_in_movie->pdata->data.actor_name << ", ";
                temp_actor_in_movie = temp_actor_in_movie->next;
            }
            cout << endl;
            temp_movie_acted_in = temp_movie_acted_in->next;
        }
    }
}

// Searches coactors of given actor, stores them and then print such that no actor repeats
void searchUniqueCoActors(ActorList *aList, MovieList *mList, string actor_name)
{
    if (!aList->search(actor_name))
    {
        cout << "Actor not Found. Try Again!";
    }
    else
    {
        set<string> co_actors{};
        ActorNode *actor = aList->currNode;
        MoviesActedIn *temp_movie_acted_in = actor->start;
        while (temp_movie_acted_in != NULL)
        {
            ActorsInMovie *temp_actor_in_movie = temp_movie_acted_in->pdata->data.pstart_actor;
            while (temp_actor_in_movie != NULL)
            {
                if (temp_actor_in_movie->pdata->data.actor_name != actor_name)
                    co_actors.insert(temp_actor_in_movie->pdata->data.actor_name);
                temp_actor_in_movie = temp_actor_in_movie->next;
            }
            temp_movie_acted_in = temp_movie_acted_in->next;
        }
        for (auto i = co_actors.begin(); i != co_actors.end(); ++i)
        {
            cout << *i << " in movie: " << endl;
            checkIfCoActors(aList, mList, actor_name, *i);
            cout << endl;
        }
    }
}


// Search coactors of coactors and print them
void searchCoActorsOfCoActors(ActorList *aList, string actor_name)
{
    if (!aList->search(actor_name))
    {
        cout << "Actor not found." << endl;
    }
    else
    {
        MoviesActedIn *temp_movie_a = aList->currNode->start;
        set<string> coactors_of_coactors{};
        while (temp_movie_a != NULL)
        {
            ActorsInMovie *temp_actor_bc = temp_movie_a->pdata->data.pstart_actor;
            while (temp_actor_bc != NULL)
            {
                if (temp_actor_bc->pdata->data.actor_name != actor_name)
                {
                    MoviesActedIn *temp_movie_bc = temp_actor_bc->pdata->start;
                    while (temp_movie_bc != NULL)
                    {
                        ActorsInMovie *temp_actor_de = temp_movie_bc->pdata->data.pstart_actor;
                        while (temp_actor_de != NULL)
                        {
                            if (temp_actor_de->pdata->data.actor_name != actor_name &&
                                temp_actor_de->pdata->data.actor_name != temp_actor_bc->pdata->data.actor_name)
                            {
                                coactors_of_coactors.insert(temp_actor_de->pdata->data.actor_name);
                            }
                            temp_actor_de = temp_actor_de->next;
                        }
                        temp_movie_bc = temp_movie_bc->next;
                    }
                }
                temp_actor_bc = temp_actor_bc->next;
            }
            temp_movie_a = temp_movie_a->next;
        }

        set<string>::iterator it = coactors_of_coactors.begin();
        while (it != coactors_of_coactors.end())
        {
            cout << *it << endl;
            it++;
        }
    }
}



// Checks if given actors have worked together
void checkIfCoActors(ActorList *aList, MovieList *mList, string actor_a, string actor_b)
{
    if (!(aList->search(actor_a) && aList->search(actor_b)))
    {
        cout << "One or both of the actors not Found. Try Again!";
    }
    else
    {
        short int count = 0;
        bool actor_a_found = false;
        bool actor_b_found = false;
        MovieNode *temp_movie = mList->start;
        ActorsInMovie *temp_actor;
        while (temp_movie != NULL)
        {
            temp_actor = temp_movie->data.pstart_actor;
            while (temp_actor != NULL)
            {
                if (temp_actor->pdata->data.actor_name == actor_a)
                {
                    actor_a_found = true;
                }
                if (temp_actor->pdata->data.actor_name == actor_b)
                {
                    actor_b_found = true;
                }
                temp_actor = temp_actor->next;
            }
            if (actor_a_found && actor_b_found)
            {
                cout << temp_movie->data.movie_title.substr(0, temp_movie->data.movie_title.length() - 2) << endl;
                count++;
            }
            actor_a_found = false;
            actor_b_found = false;

            temp_movie = temp_movie->next;
        }
        if (count == 0)
        {
            cout << "They're not Co-Actors of Each Other in Any Movie.";
        }
    }
}


// Print movies of given genre in rating wise (ascending) order.
void searchMoviesWithGenre(RatingWiseList *rList, string Genre)
{
    RatingWiseNode *temp_ratingwise_node = rList->start;
    int count = 1;
    while (temp_ratingwise_node != NULL)
    {
        RatingMovieNode *temp_ratingwise_movie = temp_ratingwise_node->start;
        while (temp_ratingwise_movie != NULL)
        {
            for (auto i = temp_ratingwise_movie->pdata->data.genre.begin(); i != temp_ratingwise_movie->pdata->data.genre.end(); i++)
            {
                if (*i == Genre)
                {
                    cout << count << " " << temp_ratingwise_movie->pdata->data.movie_title.substr(0, temp_ratingwise_movie->pdata->data.movie_title.length() - 2) << "  ";
                    cout << temp_ratingwise_movie->pdata->data.imdb_score << endl;
                    count++;
                }
            }

            temp_ratingwise_movie = temp_ratingwise_movie->next;
        }
        temp_ratingwise_node = temp_ratingwise_node->next;
    }
}


// Print all movies in rating wise (ascending) order
void moviesRatingWise(RatingWiseList *rList)
{
    RatingWiseNode *temp_ratingwise_node = rList->start;
    int i = 1;
    while (temp_ratingwise_node != NULL)
    {
        RatingMovieNode *temp_ratingwise_movie = temp_ratingwise_node->start;
        while (temp_ratingwise_movie != NULL)
        {
            cout << i << " ";
            cout << temp_ratingwise_movie->pdata->data.movie_title.substr(0, temp_ratingwise_movie->pdata->data.movie_title.length() - 2) << "  ";
            cout << temp_ratingwise_movie->pdata->data.imdb_score << endl;
            temp_ratingwise_movie = temp_ratingwise_movie->next;
            i++;
        }
        temp_ratingwise_node = temp_ratingwise_node->next;
    }
}

int main()
{
    MovieList *mList = new MovieList();
    ActorList *aList = new ActorList();
    DirectorList *dList = new DirectorList();
    GenreList *gList = new GenreList();
    YearWiseList *yList = new YearWiseList();
    RatingWiseList *rList = new RatingWiseList();
    parser(mList, aList, dList, gList, yList, rList);

    cout << "\t DSA Semester Project\n\tIMDB .csv file parser" << endl;
    cout << "Select one of the following operations: " << endl;
    short int loop = 0;
    short int input = 0;
    string input_string_1 = "";
    string input_string_2 = "";
    short unsigned int input_year = 0;
    do
    {
        cout << "1. Enter actor name to see his\\her movies in chronological order." << endl;
        cout << "2. Enter actor name to see his\\her co-actors" << endl;
        cout << "3. Enter actor name to see his\\her unique co-actors" << endl;
        cout << "4. Enter actor name to see his\\her co-actors of co-actors" << endl;
        cout << "5. Check if the two actors are coactors or not?" << endl;
        cout << "6. Enter director name to see movies directed him\\her" << endl;
        cout << "7. Enter Genre to see the directors of that genre" << endl;
        cout << "8. Enter a movie name to see its details" << endl;
        cout << "9. Enter year to see movies of that year" << endl;
        cout << "10. Print all the movies in year wise order" << endl;
        cout << "11. Enter genre to see the movies of that genre in rating wise order" << endl;
        cout << "12. Print all the movies in rating wise order" << endl;
        cout << "Press any other key to Exit" << endl;
        cout << "\nPlease select the operation: ";
        cin >> input;
        cout << endl
             << endl;
        switch (input)
        {
        case 1:
            cout << "Enter actor name: ";
            cin.ignore();
            getline(cin, input_string_1);
            searchActor(aList, yList, input_string_1);
            break;
        case 2:
            cout << "Enter actor name: ";
            cin.ignore();
            getline(cin, input_string_1);
            searchCoActorsOfActor(aList, input_string_1);
            break;
        case 3:
            cout << "Enter actor name: ";
            cin.ignore();
            getline(cin, input_string_1);
            searchUniqueCoActors(aList, mList, input_string_1);
            break;
        case 4:
            cout << "Enter actor name: ";
            cin.ignore();
            getline(cin, input_string_1);
            searchCoActorsOfCoActors(aList, input_string_1);
            break;
        case 5:
            cout << "Enter actor 01 name: ";
            cin.ignore();
            getline(cin, input_string_1);
            cout << "Enter actor 02 name: ";
            getline(cin, input_string_2);
            checkIfCoActors(aList, mList, input_string_1, input_string_2);
            break;
        case 6:
            cout << "Enter director name: ";
            cin.ignore();
            getline(cin, input_string_1);
            searchDirector(dList, input_string_1);
            break;
        case 7:
            cout << "Enter Genre: ";
            cin.ignore();
            getline(cin, input_string_1);
            moviesOfDirectorOfGivenGenre(gList, input_string_1);
            break;
        case 8:
            cout << "Enter movie name in full (case sensitive): ";
            cin.ignore();
            getline(cin, input_string_1);
            searchMovie(mList, input_string_1);
            break;
        case 9:
            cout << "Enter Year (1916-2016): ";
            cin >> input_year;
            searchMoviesWithYear(yList, input_year);
            break;
        case 10:
            moviesYearWise(yList);
            break;
        case 11:
            cout << "Enter genre:";
            cin.ignore();
            getline(cin, input_string_1);
            searchMoviesWithGenre(rList, input_string_1);
            break;
        case 12:
            moviesRatingWise(rList);
            break;
        default:
            exit(0);
            break;
        }
        cout << endl;
        cout << "Do you want to continue? Press any digit to continue or (-1) to exit" << endl;
        cin >> input;
        cout << endl
             << endl
             << endl;
    } while (input != -1);
    return 0;
}