const express = require('express');
const path = require('path');
const cookie_parser = require('cookie-parser');
const { env } = require('process');

require('dotenv').config({ path: "config.env" });

const app = express();

app.use(express.urlencoded({ extended: false }));
app.use(cookie_parser());

app.post("/login", (req, res) => {
    const username = req.body.username
    if (!username) res.sendStatus(400);
    if (username === "admin") res.send("Nope");

    res.cookie("user", username, { httpOnly: true })
        .redirect(req.path);
});

app.get("/me", (req, res) => {
    const username = req.cookies.user;
    if (!username) res.sendStatus(400);
    else if (username === "admin") {
        res.send(env.FLAG);
    } else res.send("Try logging in as admin if you want the flag");
})


app.use(express.static(path.join(__dirname, "views")));


app.listen(env.PORT, () => console.log("Server started"));