-- creating the databse
CREATE DATABASE pulseScan;

--use place_holder database
USE pulseScan;

-- creating placeholder columns
CREATE TABLE users (
user_name VARCHAR(255) NOT NULL,
user_password VARCHAR(255) NOT NULL,
PRIMARY KEY (user_name)
);

CREATE TABLE user_scan (
hasScan INTEGER NOT NULL,
scan_time INTEGER NOT NULL,
ID INTEGER NOT NULL
PRIMARY KEY (ID)
);





-- SELECT * FROM people WHERE height = (SELECT MAX (height) FROM people);

-- SELECT MAX (height) FROM pepple;

-- SELECT *
-- FROM people
-- WHERE height NOT IN (SELECT MAX (height) FROM people)
-- ORDER BY height DESC;
