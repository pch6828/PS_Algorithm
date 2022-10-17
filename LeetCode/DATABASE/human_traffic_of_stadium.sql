SELECT id, visit_date, people
FROM (SELECT id, visit_date, people, 
             LAG(people, 2) OVER (ORDER BY id) as prev2,
             LAG(people, 1) OVER (ORDER BY id) as prev1,
             LEAD(people, 1) OVER (ORDER BY id) as nxt1,
             LEAD(people, 2) OVER (ORDER BY id) as nxt2 
      FROM Stadium)t 
WHERE (people>=100 AND prev2>=100 AND prev1>=100) OR 
      (people>=100 AND nxt1>=100 AND prev1>=100) OR 
      (people>=100 AND nxt2>=100 AND nxt1>=100);