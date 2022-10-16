SELECT name
FROM SalesPerson
WHERE name NOT IN (SELECT s.name
                   FROM SalesPerson s, Company c, Orders o
                   WHERE o.com_id=c.com_id AND o.sales_id=s.sales_id AND c.name="RED");