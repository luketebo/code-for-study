<template>
    <nav class="header container">
        <ul class="row">
            <li class="col-sm">
                <a>
                    <span>Work</span>
                </a>
            </li>
            <li><a><span>About</span></a></li>
            <li><a><span>Wip</span></a></li>
            <li><a><span>Contact</span></a></li>
            <li><a><span>icon</span></a></li>
            <li><a><span>github icon</span></a></li>
            <li><a><span>Blog</span></a></li>
        </ul>
    </nav>
</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import 'bootstrap/dist/css/bootstrap.min.css'
import 'bootstrap/dist/js/bootstrap.min.js'

</script>
<style scoped lang='less'>
@border: #ccc;

.header {
    display: flex;
    height: 10vh;
    justify-content: center;
    align-items: center;
    border: 5px solid @border;
    margin-left: 10%;
    margin-right: 10%;

}

.header ul {
    display: flex;
}

.header ul li {
    display: flex;
    justify-content: center;
    align-items: center;
    border: 1px solid @border;
}
</style>