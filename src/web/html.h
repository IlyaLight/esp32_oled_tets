const char HEAD_HTMLPAGE[] = R"(
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="icon" href="data:,"> 
        <style>
            body,input,button{
                font-family:Helvetica;
                text-align:center;
                font-size:1.8rem;
                background-color:black;
                color: white;
                }
                input,button:focus{ outline:0; }
                input{
                    border:0;
                    border-bottom:2px solid white;
                    text-align:left;
                }
                button{
                    border:2px solid white;
                    border-radius:6px;
                    width: 300px;
                }
                button:active {
                background: gray;
                }
        </style>
    </head>
)";

const char BODY_SETTINGS_HTMLPAGE[] = R"(
    <body> 
      <h2>Wifi seting</h2>
            <form action="/save" method="post">
            <p><input class="input" name="ssid" type="text"  placeholder="@@ssid@@"/></p>
            <p><input class="input" name="password" type="text"  placeholder="@@pass@@"/></p>
            <p><button type="submit" >SAVE</button></p>
        </form>
    </body>
</html>
)";

const char BODY_SAVE_HTMLPAGE[] = R"(
    <body> 
        <h2>Wifi credentials is saved</h2>
        <p>the controller will try to connect to the wifi network with new data, if successful, the LED will give a long signal</p>
    </body> 
</html>
)";