SELECT t.request_at AS DAY, ROUND(SUM(IF(t.status<>'completed' AND c.banned='No' AND d.banned='No', 1, 0))/SUM(IF(c.banned='No' AND d.banned='No', 1, 0)), 2) AS 'Cancellation Rate'
FROM Trips t, Users c, Users d
WHERE t.client_id=c.users_id AND t.driver_id=d.users_id AND request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY DAY
HAVING ROUND(SUM(IF(t.status<>'completed' AND c.banned='No' AND d.banned='No', 1, 0))/SUM(IF(c.banned='No' AND d.banned='No', 1, 0)), 2) IS NOT NULL;