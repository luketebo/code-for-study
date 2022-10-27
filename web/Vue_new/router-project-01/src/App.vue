<template>

    <div>
      demo
      <router-link to="/">Login</router-link>
      <router-link style="margin-left: 100px" to="/reg">Reg</router-link>
      <hr/>
      <RouterView></RouterView>
      <!-- <Login></Login> -->
    </div>

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'
import Login from './components/login.vue'

</script>
<style scoped lang='less'>

</style>