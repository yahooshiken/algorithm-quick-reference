package sorting

type SortType string

const (
	asc  = SortType("asc")
	desc = SortType("desc")
)

type Sorter interface {
	Sort(arr []int, sortType SortType) []int
}

func Compare(x int, y int, sortType SortType) bool {
	if sortType == "asc" {
		return x > y
	} else {
		return x < y
	}
}
