# coding against csrf using php


// simple way in php file, but not recommanded.
```
<?php

$_SESSION['token'] = sha1(uniqid(mt_rand(), true)); 

if ($_SERVER['request_method'] === 'POST') {
	if($_POST['token'] !== $_SESSION['token']) {
		//error handing 
	}

}
```
// on php7
```
$_SESSION['token'] = bin2hex(random_bytes(32))

```

//over php5.3+

```
$_SESSION['token'] = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));

```

and I can use hash_equals() (PHP 5.6+ only) to compare between session and post. on server-side

```
if (hash_equals($_SESSION['token'], $_POST['token'])) {
	//Proceed to process the form data.
} 

```

//in html file

```
//between form tag

<input type="hidden" name="token" value="<?php echo htmlspecialchars($_SESSION['token'],
 ENT_QUOTES, 'UTF-8'); ?>">

```