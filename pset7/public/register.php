<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        //validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide a username.");
        }
        else if(empty($_POST["password"]))
        {
            apologize("You must provide a password.");
        }
        else if (empty($_POST["comfirmation"]))
        {
            apologize("You must confirm your password.");
        }
        else if ($_POST["comfirmation"]!=$_POST["password"])
        {
            apologize("The password and it's comfirmation doesn't match.");
        }
    }
    //query username from DB to check if it already exists
    $rows=query("SELECT*FROM users WHERE username = ?"/ $_POST["username"]);
    
    //insert a new user
    query("INSERT INTO users (username, hash, cash) VALUES(?,?,10000.00)", $_POST["username"], crypt($_POST["password"]));

?>
