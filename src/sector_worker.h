#ifndef __SECTOR_WORKER_H
#define __SECTOR_WORKER_H

#define	MAX_PORTALS 32
#include "sdl_head.h"
#include "libft.h"
#include <fcntl.h>

enum 					wall_type
{
	filled_wall,
	empty_wall,
	door
};

enum 					item_type
{
	object,
	key,
	enemy
};

enum 					item_state
{
	waiting,
	action,
	get_action,
	non
};


typedef struct			s_line
{
	t_point				start;
	t_point				end;
}						t_line;

typedef	struct			s_vector
{	
	float				x;
	float				y;
	float				z;
}						t_vector;

typedef struct 			s_item
{
	SDL_Surface			*id_text[4];
	t_vector			pos;
	enum item_state		state;
	enum item_type 		type;
	unsigned			id;
	unsigned 			size;
	float				dist_to_player;
	struct s_item		*next;
}						t_item;

typedef	struct			s_wall
{
	struct s_sector		*sectors[2];
	SDL_Surface			*texture;
	t_vector			start;
	t_vector			end;
	enum wall_type		type;
	unsigned short		id;
	unsigned short 		close;
}						t_wall;

typedef struct			s_sector
{
	t_wall				**wall;
	SDL_Surface			*floor_tex;
	SDL_Surface			*ceil_tex;
	float				floor;
	float				ceil;
	signed short		portals[MAX_PORTALS];
	unsigned short 		sector;
	unsigned short		n_walls;
	t_item				*items;
	t_item				*enemies;
	struct s_sector		*next;
}						t_sector;

t_sector			*new_sector();
t_sector			*crate_new_sector(float	floor, float ceil);
t_item				*new_item();
t_item				*create_new_item(int x, int y);

void				add_next_sector(t_sector **main, t_sector *next);
void 				add_next_item(t_item *head, t_item *new); 

void				delete_sectors(t_sector *sec);
void				delete_walls(t_wall **wals, unsigned count);
void				delete_items_list(t_item *items);
void 				delete_item_by_id(t_item *items, unsigned id);

void				list_sectors(t_sector *head);
void				list_walls(t_wall **walls, int size);
void				list_items(t_item *items);
void 				swap_items(t_item *elem1, t_item *elem2);

#endif