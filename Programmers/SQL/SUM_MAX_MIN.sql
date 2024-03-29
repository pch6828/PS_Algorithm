-- 최댓값 구하기
SELECT MAX(A.DATETIME)
FROM ANIMAL_INS AS A;
-- 최솟값 구하기
SELECT MIN(A.DATETIME)
FROM ANIMAL_INS AS A;
-- 동물 수 구하기
SELECT COUNT(*)
FROM ANIMAL_INS;
-- 중복 제거하기
SELECT COUNT(DISTINCT NAME)
FROM ANIMAL_INS;
-- 가장 비싼 상품 구히가
SELECT MAX(PRICE) AS MAX_PRICE
FROM PRODUCT;
-- 가격이 제일 비싼 식품의 정보 출력하기
SELECT *
FROM FOOD_PRODUCT
WHERE PRICE=(SELECT MAX(PRICE) FROM FOOD_PRODUCT);
