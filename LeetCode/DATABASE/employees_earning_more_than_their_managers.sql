# Write your MySQL query statement below

SELECT E1.Name as Employee
FROM Employee as E1 JOIN Employee as E2 ON E1.ManagerId = E2.Id
WHERE E1.Salary > E2.Salary