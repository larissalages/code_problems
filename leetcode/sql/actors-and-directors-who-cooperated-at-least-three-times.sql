SELECT ad.actor_id, ad.director_id
FROM ActorDirector ad
GROUP BY ad.actor_id, ad.director_id
HAVING COUNT(timestamp) >= 3