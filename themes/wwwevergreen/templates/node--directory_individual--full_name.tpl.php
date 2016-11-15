<?php

/**
Just give us a normal name (because, remember, the node's title is their CAS name!)
 */
 
 print render($content['field_first_name']) . ' ' . render($content['field_last_name']);
?>