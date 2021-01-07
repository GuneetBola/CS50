SELECT DISTINCT(movies.title) FROM stars
JOIN people ON stars.person_id = people.id
JOIN ratings ON stars.movie_id = ratings.movie_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name == "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;