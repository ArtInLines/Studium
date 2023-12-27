```SQL

SELECT * FROM (
	SELECT t.continent, '' AS t.country, '' AS t.city, sum(f.profit), avg(f.cost)
	FROM Facts f
	JOIN Ort t ON f.ort_id = t.id
	GROUP BY t.continent

	UNION

	SELECT t.continent, t.country, '' AS t.city, sum(f.profit), avg(f.cost)
	FROM Facts f
	JOIN Ort t ON f.ort_id = t.id
	GROUP BY t.continent, t.country

	UNION

	SELECT t.continent, t.country, t.city, sum(f.profit), avg(f.cost)
	FROM Facts f
	JOIN Ort t ON f.ort_id = t.id
	GROUP BY t.continent, t.country, t.city
)
ORDER BY t.continent, t.country, t.city;

```

```SQL
CREATE TABLE PROD_MASTER(
	M_ID Primary Key,
)

CREATE TABLE PROD_SLAVE(
	M_ID Foreign Key,
	P_ID Primary Key,
	P_Version Integer,
	VALID_FROM Date,
	INVALID_FROM Date,
	Name,
	....
)

SELECT ....
JOIN PROD_SLAVE p ON ..
WHERE p.valid_from <= 24.12.22 AND p.invalid_from > 24.12.22
```