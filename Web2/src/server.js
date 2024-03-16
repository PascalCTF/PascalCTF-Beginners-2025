const express = require('express');
const path = require('path');
const cookie_parser = require('cookie-parser');
const { env } = require('process');

const app = express();

app.use(express.urlencoded({ extended: false }));
app.use(cookie_parser());

app.post("/login", (req, res) => {
    const username = req.body.username
    if (!username) res.sendStatus(400);
    if (username === "admin") res.send("Nope");
    else {
        res.cookie("user", username, { httpOnly: true })
            .redirect("/");
    }

});

app.get("/me", (req, res) => {
    const username = req.cookies.user;
    if (!username || username !== "admin") {
        res.send("<a href='/login'>Log in</a> as admin if you want the flag.");
    } else res.send(env.FLAG);
});


app.use(express.static(path.join(__dirname, "public")));

app.listen(8001, () => console.log("Server started"));