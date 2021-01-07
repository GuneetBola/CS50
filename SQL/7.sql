SELECT movies.title, ratings.rating FROM movies
JOIN ratings ON ratings.movie_id = id  WHERE year = 2010
ORDER BY rating DESC, title;
/* okay so ,title is there because you want to order alphabhetically within the ratings
you used join to add the ratings column
ratings.movie is used because it is not from movies i think