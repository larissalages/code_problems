SELECT DISTINCT p.product_id, p.product_name
FROM Product p INNER JOIN Sales s ON (p.product_id = s.product_id AND (s.sale_date BETWEEN '2019-01-01' AND '2019-03-31'))
WHERE p.product_id NOT IN(
    SELECT DISTINCT product_id
    FROM Sales
    WHERE sale_date < '2019-01-01' OR sale_date > '2019-03-31'
)