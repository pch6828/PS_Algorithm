SELECT u.name as name, IFNULL(t.dist, 0) as travelled_distance
FROM Users u LEFT OUTER JOIN (SELECT user_id, SUM(distance)as dist FROM Rides GROUP BY user_id) t ON u.id=t.user_id
ORDER BY travelled_distance DESC, u.name ASC