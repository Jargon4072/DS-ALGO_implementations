CREATE DATABASE test3;
USE test3;
SHOW DATABASES;
SELECT DATABASE();
DROP DATABASE test3;      """TO DELETE A DATABASE"""
CREATE TABLE student (
  name VARCHAR(50) NOT NULL,
  email VARCHAR(60) NULL,
  city VARCHAR(40) NOT NULL,
  state VARCHAR(7) NOT NULL DEFAULT "UP",
  zip MEDIUMINT UNSIGNED NOT NULL,
  phone VARCHAR(20) NOT NULL,
  birth_date DATE NOT NULL,
  sex ENUM('M','F') NOT NULL,
  date_joined TIMESTAMP,
  id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY
);
SHOW TABLES;
/*NUMERIC TYPES:
   INT:- 1) TINYINT: -128 to 127
         2) SMALLINT: 32,768 to -32,767
         3) MEDIUMINT: 8,388,608 to -8,388,608
         4) INT: 2^31 to -2^31-1
         5) BIGINT: A number with a value no bigger than 2^63 or smaller than -2^63-1
         6) FLOAT: A number with decimal spaces, with a value no bigger than 1.1E38 or smaller than -1.1E38
         7) DOUBLE: A number with decimal spaces, with a value no bigger than 1.7E308 or smaller than -1.7E308

   CHAR:- 1) CHAR: A character string with fixed length
          2) VARCHAR: A character string with variable length
          3) BLOB: Can contain 2^16 bytes of DATA
          4) ENUM: A character string that has a limited number of total values, which you must define.
          5) SET: A list of legal possible character strings. Unlike ENUM, a SET can contain multiple values in comparison to  the one legal value with ENUM.

    DATE AND TIME:- 1) DATE: A date value with the format of (YYYY-MM-DD)
                    2) TIME: A time value with the format of (HH:MM:SS)
                    3) DATETIME: A time value with the format of (YYYY-MM-DD HH:MM:SS)
                    4) TIMESTAMP: A time value with the format of (YYYYMMDDHHMMSS)
                    5) YEAR: A year value with the format of (YYYY)
*/
DESCRIBE student;  /*shows info about table student(field, type, key, null,default etc.)*/
INSERT INTO student VALUE ("chandan","mnnitcs4072@gmail.com","vns","UP",221004,"+91 9169306749","1996-07-25",'M',NOW(),NULL);
INSERT INTO student VALUE ("vik","chavik@gmail.com","vns","UP",221023,"+91 7169382343","1996-02-21",'M',NOW(),NULL);
INSERT INTO student VALUE ("kp","kpias@gmail.com","vns","UP",221004,"+91 9169312345","1996-01-20",'M',NOW(),NULL);
INSERT INTO student VALUE ("nik","nikcoder@gmail.com","vns","UP",221004,"+91 1234506749","1996-05-15",'M',NOW(),NULL);
INSERT INTO student VALUE ("abhi","abhitty@gmail.com","vns","UP",221004,"+91 9112345749","1996-07-05",'M',NOW(),NULL);

INSERT INTO students VALUE ("mk","mkush1@gmail.com","noida","UP",221032,"+91 9999345749","1996-03-01",'M',NOW(),NULL),("rl","rchna1@gmail.com","delhi","UP",221002,"+91 8729345749","1996-01-24",'M',NOW(),NULL), ("ag","agupta@gmail.com","ngpr","mp",221022,"+91 9000045749","1996-08-11",'F',NOW(),NULL);


UPDATE students SET state=CASE id
    WHEN 1 THEN "UP"
    WHEN 2 THEN "BHR"
    WHEN 3 THEN "UP"
    WHEN 4 THEN "UP"
    WHEN 5 THEN "MP"
    END;

UPDATE students SET city=CASE id
    WHEN 1 THEN "VNS"
    WHEN 2 THEN "GAYA"
    WHEN 3 THEN "DHANURA"
    WHEN 4 THEN "MEERUT"
    WHEN 5 THEN "MP"
    END;

SELECT * FROM students;
DELETE FROM student WHERE id>5;

CREATE TABLE class (name VARCHAR(50) NOT NULL, id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY);
INSERT INTO class VALUES
('English', NULL), ('Speech', NULL), ('Literature', NULL),
('Algebra', NULL), ('Geometry', NULL), ('Trigonometry', NULL),
('Calculus', NULL), ('Earth Science', NULL), ('Biology', NULL),
('Chemistry', NULL), ('Physics', NULL), ('History', NULL),
('Art', NULL), ('Gym', NULL);
SELECT * FROM class;

CREATE TABLE test (date DATE NOT NULL, type ENUM('T','Q') NOT NULL, class_id INT UNSIGNED NOT NULL, id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY);

CREATE TABLE score(
    student_id INT UNSIGNED NOT NULL,
    event_id INT UNSIGNED NOT NULL,
    score INT NOT NULL,
    PRIMARY KEY(event_id, student_id));

CREATE TABLE absence(
    student_id INT UNSIGNED NOT NULL,
    date DATE NOT NULL,
    PRIMARY KEY(student_id, date));

ALTER TABLE test
    ADD maxscore INT UNSIGNED NOT NULL AFTER type;

DESCRIBE test;

INSERT INTO test VALUES
  ('2014-8-25', 'Q', 15, 1, NULL),
  ('2014-8-27', 'Q', 15, 1, NULL),
  ('2014-8-29', 'T', 30, 1, NULL),
  ('2014-8-29', 'T', 30, 2, NULL),
  ('2014-8-27', 'Q', 15, 4, NULL),
  ('2014-8-29', 'T', 30, 4, NULL);

SELECT * FROM test;

DESCRIBE score;

ALTER TABLE score
    CHANGE event_id test_id INT UNSIGNED NOT NULL;

DESCRIBE score;

INSERT INTO score VALUES
    (1, 1, 15),
    (1, 2, 14),
    (1, 3, 28),
    (1, 4, 29),
    (1, 5, 15),
    (1, 6, 27),
    (2, 1, 15),
    (2, 2, 14),
    (2, 3, 26),
    (2, 4, 28),
    (2, 5, 14),
    (2, 6, 26),
    (3, 1, 14),
    (3, 2, 14),
    (3, 3, 26),
    (3, 4, 26),
    (3, 5, 13),
    (3, 6, 26),
    (4, 1, 15),
    (4, 2, 14),
    (4, 3, 27),
    (4, 4, 27),
    (4, 5, 15),
    (4, 6, 27),
    (5, 1, 14),
    (5, 2, 13),
    (5, 3, 26),
    (5, 4, 27),
    (5, 5, 13),
    (5, 6, 27),
    (6, 1, 13),
    (6, 2, 13),
    # Missed this day (6, 3, 24),
    (6, 4, 26),
    (6, 5, 13),
    (6, 6, 26),
    (7, 1, 13),
    (7, 2, 13),
    (7, 3, 25),
    (7, 4, 27),
    (7, 5, 13),
    # Missed this day (7, 6, 27),
    (8, 1, 14),
    # Missed this day (8, 2, 13),
    (8, 3, 26),
    (8, 4, 23),
    (8, 5, 12),
    (8, 6, 24),
    (9, 1, 15),
    (9, 2, 13),
    (9, 3, 28),
    (9, 4, 27),
    (9, 5, 14),
    (9, 6, 27),
    (10, 1, 15),
    (10, 2, 13),
    (10, 3, 26),
    (10, 4, 27),
    (10, 5, 12),
    (10, 6, 22);

INSERT INTO absence VALUES
    (6, '2014-08-29'),
    (7, '2014-08-29'),
    (8, '2014-08-27');

UPDATE absences set student_id=case student_id
    when 6 then 14
    when 7 then 15
    when 8 then 16
    end;

SHOW TABLES;

RENAME TABLE
    absence to absences,
    class to classes,
    score to scores,
    student to students,
    test to tests;

SHOW TABLES;

SELECT name,state FROM students WHERE STATE="UP";
SELECT name,state FROM students WHERE DAY(birth_date)>15;
SELECT name,state FROM students WHERE DAY(birth_date)>15 or state="UP";
SELECT name,state FROM students WHERE DAY(birth_date)>15 and state="UP";

SELECT name,state FROM students WHERE DAY(birth_date)>15 or state="UP" ORDER by name;

SELECT name,state FROM students WHERE DAY(birth_date)>15 or state="UP" ORDER by name DESC; /*desc is used for decending order */

SELECT * from students limit 2; /*prints first two results */
SELECT * from students limit 2,5; /*prints from 3 to 5 */

select concat(name, ",", sex) as "name_detail", concat(city," ", state) as "hometown" from students; /*concat merges two field in one with provided name */

SELECT name, email from students where name like "a%" or name like "%n"; /* 'a%':- begins from a, '%n':-ends with n*/
/* '___y':- name with 4 characters and ends with y*/

SELECT DISTINCT state from students order by state;  /*distinct prints a state only once*/

SELECT count(DISTINCT state) from students;     /*conts different states */

/* QUESTION: FIND NO. OF STUDENTS FROM DISTINCT CITIES. */
SELECT COUNT(*) FROM students where state="UP";

select state,count(*) from students group by state;     /*gives the states and no of students in that state*/

select Month(birth_date) as 'Month',count(*) from students group by Month order by Month;

select state,count(state) as amount from students;

select test_id as 'test',
       min(score) as min,
       max(score) as max,
       max(score)-min(score) as 'range',
       sum(score) as total,
       avg(score) as average
       from scores
       group by test_id;

/* The Built in Numeric Functions (SLIDE)
ABS(x) : Absolute Number: Returns the absolute value of the variable x.

ACOS(x), ASIN(x), ATAN(x), ATAN2(x,y), COS(x), COT(x), SIN(x), TAN(x) :Trigonometric Functions : They are used to relate the angles of a triangle to the lengths of the sides of a triangle.

AVG(column_name) : Average of Column : Returns the average of all values in a column. SELECT AVG(column_name) FROM table_name;

CEILING(x) : Returns the smallest number not less than x.

COUNT(column_name) : Count : Returns the number of non null values in the column. SELECT COUNT(column_name) FROM table_name;

DEGREES(x) : Returns the value of x, converted from radians to degrees.

EXP(x) : Returns e^x

FLOOR(x) : Returns the largest number not grater than x

LOG(x) : Returns the natural logarithm of x

LOG10(x) : Returns the logarithm of x to the base 10

MAX(column_name) : Maximum Value : Returns the maximum value in the column. SELECT MAX(column_name) FROM table_name;

MIN(column_name) : Minimum : Returns the minimum value in the column. SELECT MIN(column_name) FROM table_name;

MOD(x, y) : Modulus : Returns the remainder of a division between x and y

PI() : Returns the value of PI

POWER(x, y) : Returns x ^ Y

RADIANS(x) : Returns the value of x, converted from degrees to radians

RAND() : Random Number : Returns a random number between the values of 0.0 and 1.0

ROUND(x, d) : Returns the value of x, rounded to d decimal places

SQRT(x) : Square Root : Returns the square root of x

STD(column_name) : Standard Deviation : Returns the Standard Deviation of values in the column. SELECT STD(column_name) FROM table_name;

SUM(column_name) : Summation : Returns the sum of values in the column. SELECT SUM(column_name) FROM table_name;

TRUNCATE(x) : Returns the value of x, truncated to d decimal places
*/
select * from scores;

INSERT INTO scores values(6,3,24);

select * from scores where student_id=6;

select * from absences;

/*DROP column deletes a column from a table. it is used with ALTER TABLE. */

select name from students WHERE birth_date between '1996-01-21' AND '1996-07-01';

select id,name from students where name in("vik","chandan","nik");

/* NOTE: JOINING THE TABLES: */
select student_id, date, score, maxscore from tests,scores where date='2014-08-25' and tests.id=scores.test_id;

select name,student_id, date, score, maxscore from students,tests,scores where date='2014-08-25' and tests.id=scores.test_id and scores.student_id=students.id;

/* finding total no of absences(if any) for students: (here in this query it will only show student with absences)*/
select students.id,students.name,count(absences.date) as absences from students,absences where students.id=absences.student_id group by students.id;

/*NOTE: left join shows all the entries not just the student with absences, with their count. */

select students.id, students.name, count(absences.date) as absences from students left join absences on students.id=absences.student_id group by students.id;

/* NOTE: INNER JOIN takes all the data from both tables and puts them together */
select students.name, scores.test_id,scores.score from students INNER JOIN scores on students.id=scores.student_id where scores.score<=15 order by scores.test_id;
