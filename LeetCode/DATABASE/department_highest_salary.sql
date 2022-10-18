SELECT Department, Employee, Salary
FROM( SELECT d.name as Department, 
             e.name as Employee, 
             e.salary as Salary, 
             (MAX(Salary) OVER (PARTITION BY departmentId)) AS max_dept_salary
     FROM Department d, Employee e
     WHERE d.id=e.departmentId) t
WHERE Salary=max_dept_salary