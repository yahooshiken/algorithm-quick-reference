lazy val root = (project in file(".")).settings(
  inThisBuild(
    List(
      organization := "com.example",
      scalaVersion := "2.13.3"
    )
  ),
  name := "scalatest-example"
)

fork := true
javaOptions in Test ++= Seq("-Xss16M")

libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.2" % Test
