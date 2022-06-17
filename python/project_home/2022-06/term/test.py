import GetMessage as gm

# gm.Time 时间  gm.Data  信息  gm.Station 站点

# GetDownTime  时间    上车时间    站点
gm.GetDownTime(gm.Time, "08:00", "6")
# GetStationMessage 时间    站点信息    站点
gm.GetStationMessage(gm.Time, gm.Station, "6")
# NearestStation  站点信息    坐标
gm.NearestStation(gm.Data, 3, 5)
