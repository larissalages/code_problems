SELECT E.name as Employee
FROM Employee E
JOIN Employee M ON E.managerID = M.id
WHERE E.salary > M.salary;
