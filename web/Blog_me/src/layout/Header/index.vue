<template>

 <div class="header">
    <nav>
        <ul>
            <li><a>Work</a></li>
            <li><a>About</a></li>
            <li><a>Wip</a></li>
            <li><a>Contact</a></li>
            <li><a>icon</a></li>
            <li><a>icon</a></li>
        </ul>
    </nav>
 </div>
</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'

</script>
<style scoped lang='less'>
@border: #ccc;
.header{
    display: flex;
    height: 10vh;
    width: 100%;
    justify-content: center;
    border: 1px solid @border;
}
.header nav{
    display: flex;
    width: 90%;
}
.header nav ul {
    color: @border;
    display: flex;
    justify-content: center;
    align-items: center;
    background-color: black; 
}
.header nav ul li{
    float: left;
    border: 1px solid @border;
    
}
.header nav ul li a {
    display: flex;
    justify-content: center;
    align-items: center;
}


</style>