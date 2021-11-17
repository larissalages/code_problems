SELECT D.name AS 'Department', E.name AS 'Employee', E.salary As 'Salary'
FROM Employee E
JOIN Department D ON E.departmentId = D.id
WHERE (D.id, E.salary) in (
    SELECT
        departmentId, MAX(salary)
    FROM Employee
    GROUP BY departmentId
)
