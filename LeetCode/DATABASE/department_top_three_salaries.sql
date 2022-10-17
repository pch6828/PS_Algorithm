SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
FROM Department d, (SELECT *, DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS salary_rank 
                    FROM Employee) e
WHERE salary_rank <= 3 AND d.id = e.departmentId;