CREATE TABLE courses(course_id    varchar(6)  PRIMARY KEY, 
                     course_name  varchar(50) NOT NULL, 
                     course_topic varchar(50) NOT NULL);

INSERT INTO courses
VALUES 
  ('ORA_1' , 'Oracle Basics', 'Oracle'         )
, ('ORCL'  , 'Oracle Administration', 'Oracle' )
, ('ORA_2' , 'Oracle Advanced', 'Oracle'       )
, ('MS_XL1', 'MS Excel Basics', 'MS Office'    )
, ('MS_WD1', 'MS Word Basics', 'MS Office'     )
, ('HAPPY' , 'How to Find Happiness in Life', 'Others')
;

CREATE TABLE employee_education (
  employee_id DECIMAL(6) REFERENCES employees,
  course_id   VARCHAR(6) REFERENCES courses,
  PRIMARY KEY (employee_id,course_id)
);

truncate TABLE employee_education;

INSERT INTO employee_education
SELECT e.employee_id, c.course_id  
  FROM employees e
 CROSS JOIN courses c
 ORDER BY RANDOM() 
 FETCH FIRST 200 ROWS only
;
