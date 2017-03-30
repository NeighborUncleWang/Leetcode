# Write your MySQL query statement below
SELECT A.Name
AS Employee
FROM Employee A
INNER JOIN Employee B
ON A.ManagerId = B.Id
AND A.Salary > B.Salary;