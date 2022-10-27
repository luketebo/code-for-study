<template>

    <div class="home">
        <div class="home-left">
            <article1></article1>
            <article1></article1>
            <article1></article1>
            <article1></article1>
            <article1></article1>
            <article1></article1>
        </div>
        <div class="home-right">
            <tagMe></tagMe>
            <tag2></tag2>
        </div>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import article1 from '../article/article_01.vue'
import tagMe from '../tag/tag_me.vue'
import tag2 from '../tag/tag_02.vue'

</script>
<style scoped lang='less'>
@border: #ccc;

.home {
    width: 100%;
    height: auto;
    border: 1px solid @border;
    display: flex;
    flex-direction: row;
    justify-content: space-between;

    &-left {
        width: 70%;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        border: 1px solid @border;
    }

    &-right {
        width: 30%;
        border: 1px solid @border;

    }
}
</style>