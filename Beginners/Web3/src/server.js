const express = require('express');
const db = require('./db');
const { env } = require('process');
const path = require('path');

const app = express();

app.use(express.json());
app.use(express.urlencoded());
app.use(express.query());


app.post("/api/group-stats", async (req, res) => {
    const group = req.body.group;
    let data = await db.query(`SELECT * FROM GROUP_STATS WHERE group_id = '${group}' ORDER BY ranking ASC`).catch((err) => console.error(err));
    if(data.rowCount) {
        res.json({data: data.rows});
    }
    else res.sendStatus(404);
});

app.use(express.static(path.join(__dirname, "public")));

app.listen(env.APP_PORT);

