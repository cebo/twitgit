<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <title>Twitter OAuth in PHP</title>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
    
    <style type="text/css">
      img {border-width: 0}
      * {font-family:'Lucida Grande', sans-serif;}
    </style>
  </head>
  <body>
    <div>
      <h2>Welcome to a Twitter OAuth PHP example.</h2>

      <p>This site is a basic showcase of Twitters OAuth authentication method. If you are having issues try <a href='./clearsessions.php'>clearing your session</a>.</p>
	
	
	
	
      <p>
        Links:
        <a href='http://github.com/abraham/twitteroauth'>Source Code</a> &amp;
        <a href='http://wiki.github.com/abraham/twitteroauth/documentation'>Documentation</a> |
        Contact @<a href='http://twitter.com/abraham'>abraham</a>
      </p>
      <hr />
      <?php if (isset($menu)) { ?>
        <?php echo $menu; ?>
      <?php } ?>
    </div>
    
    
    <h3><?php echo $_SESSION['screen_name']; ?> </h3>
    
    
    




    
   <br><br><br> -----------------------------------------------------------------------------------------------
    
    
    <?php if (isset($status_text)) { ?>
      <?php echo '<h3>'.$status_text.'</h3>'; ?>
    <?php } ?>
    <p>
      <pre>
        <?php print_r($content); ?>
      </pre>
    </p>
    
   <?php if ($_SESSION['status'] == 'verified') {
        ?>
      			<div class="twitterbox">
      			  <form action="post.php" method="post" id="twitter-form">
        			  <textarea name="status" id="tweet" style="background: #ffffff"></textarea>
        			  <input type="hidden" name="ref" id="ref" />
        			  <input type="submit" value="tweet" />
              </form>
      			</div>
          <div class="signout"><a href="clearsessions.php">Sign Out</a></div>
        <?php 
        } 
	
	
	

    //$results = array();
    //$key = 0;
  	//$img = 1;
  	//$replaceWords = array("/v=/i"); 


  	 // $results["places"][$key]["followers_count"] = get_the_title();
  	 // $results["places"][$key]["desc"] = get_the_content();
  	 // $results["places"][$key]["cater"] = get_post_meta ($post->ID, 'furu_category', $single = true);
  	 // $results["places"][$key]["coords"] = get_post_meta ($post->ID, 'furu_coordinates', $single = true);
  	 // $results["places"][$key]["permalink"] = get_post_meta ($post->ID, 'furu_link', $single = true);
  	 // $results["places"][$key]["address"] =  get_post_meta ($post->ID, 'furu_address', $single = true);
    
  	  //$key++;

 // endwhile; 
 // endif;

 // $returnJSON = json_encode($results);
 // echo $returnJSON;


?>



<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.6.4/jquery.min.js"></script>
    	
	<script type="text/javascript">
    $(document).ready(function() {

      /* Submit tweet */
      $('#twitter-form').submit(function(){  
          //setup variables  
          var form = $(this),  
          formData = form.serialize(),  
          formUrl = form.attr('action'),  
          formMethod = form.attr('method'),  
          responseMsg = $('#response')  

          //show response message - waiting  
          responseMsg.hide()  
                     .addClass('response-waiting')  
                     .text('Please Wait...')  
                     .fadeIn(200);  

             //send data to server for validation  
             $.ajax({  
                 url: formUrl,  
                 type: formMethod,  
                 data: formData,  
                 success:function(data){  
                     //setup variables  
                     var responseData = jQuery.parseJSON(data),  
                         klass = '';  

                     //response conditional  
                     switch(responseData.status){  
                         case 'error':  
                             klass = 'response-error';  
                         break;  
                         case 'success':  
                             klass = 'response-success';
                             $("#tweet").html("");
                         break;  
                     }  

                     //show reponse message  
                     responseMsg.fadeOut(200,function(){  
                         $(this).removeClass('response-waiting')  
                                .addClass(klass)  
                                .text(responseData.message)  
                                .fadeIn(200,function(){  
                                    //set timeout to hide response message  
                                    setTimeout(function(){  
                                        responseMsg.fadeOut(200,function(){  
                                            $(this).removeClass(klass);  
                                        });  
                                    },3000);  
                                 });  
                      });  
                   }  
             });

          //prevent form from submitting  
          return false;  
      })



	</script>


  </body>
</html>
