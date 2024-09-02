const { env } = require('process');
const { Client } = require('pg');

const client = new Client(`psql://${env.DB_USER}:${env.DB_PASSWORD}@${env.DB_HOSTNAME}/`);

client.connect((err) => {
    if (err) console.error("Failed to connect to the database: ", err, env);
    else console.log("Successfully connected to the database");
});

client.query(`DROP TABLE IF EXISTS GROUPS, GROUP_STATS, FLAG`);

client.query(`CREATE TABLE IF NOT EXISTS GROUPS (
    id CHAR NOT NULL PRIMARY KEY
)`);

client.query(`CREATE TABLE IF NOT EXISTS GROUP_STATS (
    group_id CHAR NOT NULL,
    team_name VARCHAR(32) NOT NULL,
    ranking INT NOT NULL,
    points INT NOT NULL,
    wins INT NOT NULL,
    draws INT NOT NULL,
    losses INT NOT NULL,
    goal_difference INT NOT NULL,
    PRIMARY KEY(group_id, team_name),
    FOREIGN KEY (group_id) REFERENCES GROUPS (id)
)`);

client.query(`INSERT INTO GROUPS VALUES ('A'), ('B'), ('C'), ('D'), ('E'), ('F')`);


client.query(`
INSERT INTO GROUP_STATS (group_id, team_name, ranking, points, wins, draws, losses, goal_difference) VALUES
('A', 'Germany', 1, 7, 2, 1, 0, 6),
('A', 'Switzerland', 2, 5, 1, 2, 0, 2),
('A', 'Hungary', 3, 3, 1, 0, 2, -3),
('A', 'Scotland', 4, 1, 0, 1, 2, -5),
('B', 'Spain', 1, 9, 3, 0, 0, 5),
('B', 'Italy', 2, 4, 1, 1, 1, 0),
('B', 'Croatia', 3, 2, 0, 2, 1, -3),
('B', 'Albania', 4, 1, 0, 1, 2, -2),
('C', 'England', 1, 5, 1, 2, 0, 1),
('C', 'Denmark', 2, 3, 0, 3, 0, 0),
('C', 'Slovenia', 3, 3, 0, 3, 0, 0),
('C', 'Serbia', 4, 2, 0, 2, 1, -1),
('D', 'Austria', 1, 6, 2, 0, 1, 2),
('D', 'France', 2, 5, 1, 2, 0, 1),
('D', 'Netherlands', 3, 4, 1, 1, 1, 0),
('D', 'Poland', 4, 1, 0, 1, 2, -3),
('E', 'Romania', 1, 4, 1, 1, 1, 1),
('E', 'Belgium', 2, 4, 1, 1, 1, 1),
('E', 'Slovakia', 3, 4, 1, 1, 1, 0),
('E', 'Ukraine', 4, 4, 1, 1, 1, -2),
('F', 'Portugal', 1, 6, 2, 0, 1, 2),
('F', 'Turkey', 2, 6, 2, 0, 1, 0),
('F', 'Georgia', 3, 4, 1, 1, 1, 0),
('F', 'Czech Republic', 4, 1, 0, 1, 2, -2);
`)

client.query(`CREATE TABLE IF NOT EXISTS FLAG (
    flag VARCHAR(64) PRIMARY KEY 
)`)

client.query(`INSERT INTO FLAG VALUES ($1)`, [env.FLAG], (err) => console.log(err));

module.exports = client;