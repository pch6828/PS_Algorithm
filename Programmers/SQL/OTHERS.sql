-- 2021 Dev-Matching: 웹 백엔드 개발자(상반기)
-- 헤비 유저가 소유한 장소
SELECT *
FROM PLACES
WHERE HOST_ID IN (SELECT HOST_ID 
                  FROM PLACES 
                  GROUP BY HOST_ID 
                  HAVING COUNT(*)>1)
ORDER BY ID;
-- Summer/Winter Coding(2019)
-- 우유와 요거트가 담긴 장바구니
SELECT DISTINCT CART_ID
FROM CART_PRODUCTS
WHERE CART_ID IN (SELECT CART_ID 
                  FROM CART_PRODUCTS 
                  WHERE NAME='Milk') AND
      CART_ID IN (SELECT CART_ID 
                  FROM CART_PRODUCTS 
                  WHERE NAME='Yogurt')
ORDER BY CART_ID;