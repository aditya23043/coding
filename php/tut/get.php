<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>PHP Stuff</title>
</head>

<style>
	html {
		padding: 1rem;
		background-color: #1e1e1e;
		color: white;
	}

	input {
		background-color: #1e1e1e;
		border-style: solid;
		border-color: #5e5e5e;
		padding: 0.5rem;
		font-size: 0.8rem;
		color: #aaaaaa;
	}

	* {
		margin: 0.2rem;
		font-family: "Agave Nerd Font Mono";
		font-weight: bold;
	}
</style>

<body>
	<form action="index.php" method="get">

		<br>

		<label for="">Username: </label><br>
		<input type="text" name="username"><br>
		<br>

		<label for="">Password: </label><br>
		<input type="text" name="password"><br>
		<br>

		<input style="padding:0.5rem;" type="submit" value="Log In">

	</form>
</body>

<?php
echo "<br>";
echo "Username: {$_GET["username"]} <br>";
echo "Password: {$_GET["password"]} <br>";
?>

</html>
