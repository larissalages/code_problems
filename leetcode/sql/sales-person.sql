SELECT DISTINCT sp.name
FROM SalesPerson sp LEFT OUTER JOIN Orders o ON sp.sales_id = o.sales_id
WHERE sp.sales_id NOT IN(
    SELECT o2.sales_id
    FROM Orders o2 INNER JOIN Company c ON o2.com_id = c.com_id
    WHERE c.name = "RED"
)