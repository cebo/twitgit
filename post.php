<?php
/**
 * @file
 * User has successfully authenticated with Twitter. Access tokens saved to session and DB.
 */

session_start();
$status = (isset($_POST["status"])) ? $_POST["status"] : null;
require_once('twitteroauth/twitteroauth.php');
require_once('config.php');

/* If access tokens are not available redirect to connect page. */
if (empty($_SESSION['access_token']) || empty($_SESSION['access_token']['oauth_token']) || empty($_SESSION['access_token']['oauth_token_secret'])) {
    header('Location: ./clearsessions.php');
}
/* Get user access tokens out of the session. */
$access_token = $_SESSION['access_token'];

/* Create a TwitterOauth object with consumer/user tokens. */
$connection = new TwitterOAuth(CONSUMER_KEY, CONSUMER_SECRET, $access_token['oauth_token'], $access_token['oauth_token_secret']);

/* If method is set change API call made. Test is called by default. */
$content = $connection->get('account/verify_credentials');

if ($status != null) {
  $connection->post('statuses/update', array('status' => $status));
  $postStatus = "success";
  $myusername = "success";
  $postMessage = "You tweeted: " . $status;
} else {
  $postStatus = "error";
  $postMessage = "You didn't provide any information";
}

$data = array(
  'status' => $postStatus,
  'message' => $postMessage,
  'username' => ''
);

echo json_encode($data);
