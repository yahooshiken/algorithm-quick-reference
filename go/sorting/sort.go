package sorting

type SortType string

const (
	asc  = SortType("asc")
	desc = SortType("desc")
)

type Sorter interface {
	Sort(arr []int, sortType SortType) []int
	Compare(x int, y int, sortType SortType) bool
}
