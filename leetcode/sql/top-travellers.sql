SELECT u.name, SUM(
    CASE
        WHEN r.distance IS NULL
            THEN 0
        ELSE r.distance
    END
) AS travelled_distance
FROM Users u LEFT OUTER JOIN Rides r ON (u.id = r.user_id)
GROUP BY u.id
ORDER BY SUM(r.distance) DESC, u.name ASC