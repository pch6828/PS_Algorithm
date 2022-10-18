SELECT DISTINCT num as ConsecutiveNums
FROM (SELECT num, 
             LAG(num, 1) OVER (ORDER BY id ASC) AS prevNum, 
             LEAD(num, 1) OVER (ORDER BY id ASC) AS nextNum 
      FROM Logs) t
WHERE num=prevNum AND num=nextNum;