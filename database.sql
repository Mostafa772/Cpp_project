CREATE TABLE Courses(
		id INT PRIMARY KEY,
		course_name TEXT NOT NULL,
		credits INT NOT NULL,
		teacher TEXT ,
		teacher_id INT ,
		department_name TEXT NOT NULL ,
		department_id INT NOT NULL,
		pre_requests INT [],
		resources TEXT,
		    FOREIGN KEY (teacher_id) REFERENCES Teachers(id),
		    FOREIGN KEY (department_id) REFERENCES Departments(id)
      );


 CREATE TABLE Teachers(
		id int primary key ,
		name text NOT NULL ,
		department TEXT NOT NULL ,
		department_id INT NOT NULL ,
		occupation TEXT NOT NULL,
		email TEXT NOT NULL,
              FOREIGN KEY (department_id) REFERENCES Departments(id)
      );

CREATE TABLE Departments(
		id INT PRIMARY KEY,
		department TEXT NOT NULL ,
		head_of_department TEXT NOT NULL ,
		head_of_department_id INT NOT NULL,
		establishing_year INT NOT NULL,
		    FOREIGN KEY (head_of_department_id) REFERENCES Teachers(id)
	);

CREATE TABLE Degrees(
          id INT PRIMARY KEY ,
          degree TEXT NOT NULL ,
          department TEXT NOT NULL ,
          department_id INT NOT NULL ,
          level  TEXT NOT NULL ,
          coordinator TEXT NOT NULL ,
          coordinator_id INT NOT NULL ,
          fee INT,
            FOREIGN KEY (coordinator_id) REFERENCES Teachers(id),
            FOREIGN KEY (department_id) REFERENCES Teachers(id)
      );
      
      
INSERT INTO Courses (id, course_name, credits, teacher,  teacher_id, department_name, department_id, pre_requests, resources) VALUES
                    (1, 'intro to biology', 3, 'Mikhail Ahmadov', 1, 'biology department', 2, 0, 'wikipedia');
INSERT INTO Courses (id, course_name, credits, teacher,  teacher_id, department_name, department_id, pre_requests, resources) VALUES
                    (2, 'intro to math analysis', 6, 'Sasha Dickinson', 2, 'math department', 1, 0, 'wikipedia');
INSERT INTO Courses (id, course_name, credits, teacher,  teacher_id, department_name, department_id, pre_requests, resources) VALUES
                    (3, 'intro to programming 1', 3, 'Esmay Green', 3, 'applied math department', 3, 0, 'wikipedia');
INSERT INTO Courses (id, course_name, credits, teacher,  teacher_id, department_name, department_id, pre_requests, resources) VALUES
                    (4, 'intro to programming 2', 3, 'Esmay Green', 3, 'applied math department', 3, 0, 'wikipedia');
INSERT INTO Courses (id, course_name, credits, teacher,  teacher_id, department_name, department_id, pre_requests, resources) VALUES
                    (5, 'computer architecture', 3, 'Wendy Mathews', 4,  'applied math department', 3, 3, 'wikipedia');
INSERT INTO Courses (id, course_name, credits, teacher,  teacher_id, department_name, department_id, pre_requests, resources) VALUES
                    (6, 'python programming', 3, 'Ikra Nunez', 6,'applied math department', 3, 3, 'wikipedia');
INSERT INTO Courses (id, course_name, credits, teacher,  teacher_id, department_name, department_id, pre_requests, resources) VALUES
                    (7, 'data structures and algorithms', 4, 'Geoffrey Sanchez', 7, 'applied math department', 3, 3, 'wikipedia');


INSERT INTO Departments (id, department, head_of_department, head_of_department_id, establishing_year) VALUES
                    (1, 'math department', 'Andrey Raigorodskiy', 5, 1964);
INSERT INTO Departments (id, department, head_of_department, head_of_department_id, establishing_year) VALUES
                    (2, 'biology department', 'Alexander Melerzanov', 8, 1969);
INSERT INTO Departments (id, department, head_of_department, head_of_department_id, establishing_year) VALUES
                    (3, 'applied math department', 'Alexander Dainiak', 15, 1975);
INSERT INTO Departments (id, department, head_of_department, head_of_department_id, establishing_year) VALUES
                    (4, 'physics department', 'Victoria Grineva', 13, 1969);


INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (1, 'Mikhail Ahmadov', 'biology department', 2, 'professor', 'ahmadov@gmial.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (2,'Sasha Dickinson', 'applied math department', 3, 'professor', 'sasha@gmial.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (3,'Esmay Green', 'applied math department', 3, 'professor', 'esmay@gmial.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (4,'Wendy Mathews', 'applied math department', 3, 'associate professor', 'wendy@gmial.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (5, 'Andrey Raigorodskiy', 'math department', 1, 'professor', 'andrey@gmail.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (6, 'Ikra Nunez', 'applied math department', 3, 'visiting lecturer', 'ikra@gmail.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (7, 'Geoffrey Sanchez', 'applied math department', 3, 'professor', 'geoffrey@gmail.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (8, 'Alexander Melerzanov', 'biology department', 2, 'professor', 'melerzanov@gmail.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (13, 'Victoria Grineva', 'physics department', 4, 'professor', 'grineva@gmail.edu');
INSERT INTO Teachers (id, name, department, department_id, occupation, email) VALUES
                    (15, 'Alexander Dainiak', 'applied math department', 3, 'professor', 'dainiak@gmail.edu');

INSERT INTO Degrees (id, degree, department, department_id, level, coordinator, coordinator_id, fee) VALUES
                    (1, 'computer science', 'applied math department', 3, 'bachelor', 'Alexander Dainiak', 15, 400000);
INSERT INTO Degrees (id, degree, department, department_id, level, coordinator, coordinator_id, fee) VALUES
                    (2, 'biomedical technology', 'biology department', 2, 'bachelor', 'Alexander Melerzanov', 8, 400000);
INSERT INTO Degrees (id, degree, department, department_id, level, coordinator, coordinator_id, fee) VALUES
                    (3, 'aerospace engineering', 'physics department', 4, 'bachelor', 'Victoria Grineva', 13, 400000);
