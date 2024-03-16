const express = require('express');
const db = require('./db');
const { env } = require('process');
const path = require('path');
const ejs = require('ejs');

const app = express();

app.use(express.json());
app.use(express.urlencoded());
app.use(express.query());
app.set('view engine', 'ejs');

app.post("/api/group-stats", async (req, res) => {
    const group = req.body.group;
    let data = await db.query(`SELECT * FROM GROUP_STATS WHERE group_id = '${group}' ORDER BY ranking ASC`).catch((err) => console.error(err));
    if (data === undefined || data.rows === undefined) return res.json({ data: []});
    res.json({ data: data.rows });
});

app.get('/', async (req, res) => {
    const data = await db.query(`SELECT * FROM GROUPS`).catch((err) => console.log(err));
    const rows = await data.rows;
    
    res.render("index.ejs", {
        groups: rows.map((x) => x['id'])
    });
})


app.use(express.static(path.join(__dirname, "public")));


app.listen(env.APP_PORT);
