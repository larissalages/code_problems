SELECT S.Score, COUNT(S2.Score) as `Rank`
FROM Scores S,
(SELECT DISTINCT Score FROM Scores) AS S2
WHERE S.Score <= S2.Score
GROUP BY S.id
ORDER BY S.Score DESC;