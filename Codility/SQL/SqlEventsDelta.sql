-- write your code in PostgreSQL 9.4
SELECT e1.event_type, (e1.value - e2.value) as value
FROM events e1
INNER JOIN events e2 ON e1.event_type = e2.event_type
AND e1.time = (
    SELECT temp1.time 
    from events temp1 
    WHERE temp1.event_type = e1.event_type
    ORDER BY temp1.time DESC
    LIMIT 1)
AND e2.time = (
    SELECT temp2.time
    FROM events temp2
    WHERE temp2.event_type = e2.event_type
    ORDER BY temp2.time
    DESC LIMIT 1 OFFSET 1
);