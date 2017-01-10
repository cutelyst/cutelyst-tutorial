--
-- Add users and role tables, along with a many-to-many join table
--
PRAGMA foreign_keys = ON;
CREATE TABLE users (
        id            INTEGER PRIMARY KEY,
        username      TEXT,
        password      TEXT,
        email_address TEXT,
        first_name    TEXT,
        last_name     TEXT,
        active        INTEGER
);
CREATE TABLE role (
        id   INTEGER PRIMARY KEY,
        role TEXT
);
CREATE TABLE user_role (
        user_id INTEGER REFERENCES users(id) ON DELETE CASCADE ON UPDATE CASCADE,
        role_id INTEGER REFERENCES role(id) ON DELETE CASCADE ON UPDATE CASCADE,
        PRIMARY KEY (user_id, role_id)
);
--
-- Load up some initial test data
--
INSERT INTO users VALUES (1, 'test01', 'mypass', 't01@na.com', 'Joe',  'Blow', 1);
INSERT INTO users VALUES (2, 'test02', 'mypass', 't02@na.com', 'Jane', 'Doe',  1);
INSERT INTO users VALUES (3, 'test03', 'mypass', 't03@na.com', 'No',   'Go',   0);
INSERT INTO role VALUES (1, 'user');
INSERT INTO role VALUES (2, 'admin');
INSERT INTO user_role VALUES (1, 1);
INSERT INTO user_role VALUES (1, 2);
INSERT INTO user_role VALUES (2, 1);
INSERT INTO user_role VALUES (3, 1);
