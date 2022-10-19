<template>

  <div :style="{background: `url(${bg})`}" class="box">
    <div class="box-left"></div>
    <div class="box-center"></div>
    <div class="box-right"></div>
  </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import bg from './assets/wallpaper.jpg'



</script>
<style lang='less'>
* {
  padding: 0;
  margin: 0;
}

html,
body,
#app {
  height: 100%;
}

.box {
  height: 100%;
  display: flex;
  overflow: hidden;

  &-left {
    width: 400px;
    

  }

  &-center {
    flex: 1
  }

  &-right {
    width: 400px;
   

  }
}
</style>