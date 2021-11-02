select MAX(salary) as SecondHighestSalary
from Employee
WHERE salary < (select MAX(salary) from Employee);
