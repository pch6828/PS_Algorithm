SELECT product_id, product_name
FROM Product
WHERE product_id NOT in (SELECT product_id FROM Sales WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31') AND
      product_id in (SELECT product_id FROM Sales WHERE sale_date BETWEEN '2019-01-01' AND '2019-03-31')