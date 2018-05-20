"""CREATE TABLE students( id INT NOT NULL AUTO_INCREMENT, name VARCHAR(100) NOT NULL,subject VARCHAR(200)NOT NULL, marks INT(100) NOT NULL, PRIMARY KEY(id) );"""
INSERT INTO students (id, name, subject, marks)  VALUE (1, "chan", "math", 100);
INSERT INTO students (id, name, subject, marks)  VALUE (2, "vik", "hindi", 92);
INSERT INTO students (id, name, subject, marks)  VALUE (3, "nik", "physics", 70);
INSERT INTO students (id, name, subject, marks)  VALUE (4, "abhi", "english", 87);
INSERT INTO students (id, name, subject, marks)  VALUE (5, "kp", "chemistry", 68);
SELECT * FROM students;
SELECT name,marks FROM students;
UPDATE students  SET marks= CASE id
                                 WHEN 1 THEN 100
                                 WHEN 2 THEN 92
                                 WHEN 3 THEN 70
                                 WHEN 4 THEN 87
                                 WHEN 5 THEN 68
                                 END

SELECT * FROM students;
