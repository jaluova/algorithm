<?php
$miwen = "a1zLbgQsCESEIqRLwuQAyMwLyq2L5VwBxqGA3RQAyumZ0tmMvSGM2ZwB4tws";

// 1. ROT13 解码
$rot13_decoded = str_rot13($miwen); // n1mYotDfPRFRVdEYjhDNlZjLd2Y5IjOkdTN3EDNlhzM0gzZiFTZ2MjO4gjf

// 2. 反转字符串
$reversed = strrev($rot13_decoded); // fjg4OjM2ZTiFzg0M3zhlNDE3NTdkOjI5Y2dLlZNDhjYEdVRFRfDtoYm1n

// 3. Base64 解码
$base64_decoded = base64_decode($reversed);

// 4. 逆向 ASCII +1 操作
$original = "";
for ($i = 0; $i < strlen($base64_decoded); $i++) {
    $char = substr($base64_decoded, $i, 1);
    $original .= chr(ord($char) - 1);
}

// 5. 反转字符串得到 flag
$flag = strrev($original);
echo $flag;
?>
