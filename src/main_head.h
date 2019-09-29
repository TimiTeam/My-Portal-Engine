#ifndef __MAIN_HEAD_H
#define __MAIN_HEAD_H

# include <fcntl.h>
# include <pthread.h>
# include "sdl_head.h"
# include "sectors.h"

#define W 1360
#define H 720
#define EyeHeight  5
#define DuckHeight 2.5
#define HeadMargin 1
#define KneeHeight 2
#define THREADS 4
#define DELETE 	{tmp->next = all->next; ft_memdel((void**)&all); return ;}
# define DEL tmp = curr->next;delete_projectile(projectiles, curr);curr = tmp;
# define CON {DEL; continue;}

typedef struct  	s_rect
{
	t_point			pos;
	t_point			size;
}     				t_rect;

typedef struct		s_scaler
{
	int				result;
	int				bop;
	int				fd;
	int				ca;
	int				cache;
}					t_scaler;

typedef struct		s_draw_data
{
	int 			ytop[W];
	int				ybottom[W];
	float 			start;
	float			end;
	float			player_current_height;
	float			floor_y_e;
	float			floor_y_s;
	float			ceil_y_e;
	float			ceil_y_s;
	float			n_ceil_y_s;
	float			n_ceil_y_e;
	float			n_floor_y_s;
	float			n_floor_y_e;
	float 			diff_ceil;
	float 			diff_floor;
	int				floor_height;
	int				ceil_height;
	int				n_floor_height;
	int				n_ceil_height;	
}					t_draw_data;

typedef struct		s_gun
{
	float 			state;
	SDL_Surface		*frame[10];
	SDL_Surface		*icon;
	enum e_gun_type	type;
	int				max_frames;
	int				ammo;
	float			damage;
	float			rate_of_fire;
}					t_gun;

typedef struct		s_player
{	
	SDL_Surface		*sky;
	t_sector 		*curr_sector;
	t_item			*inventar;
	t_gun			**all_guns;
	t_gun			*gun[3];
	t_vector		pos;
	t_point			half_win_size;
	t_gun			*current_gun;
	float 			speed;
	float			yaw;
	float			angle;
	float			sin_angl;
	float			cos_angl;
	float 			hfov;
	float 			vfov;
	float			m_vfov;
	float			m_hfov;
	float			velocity;
	int				height;
	int				health;
	unsigned char	fall;
	char			sit;
	unsigned char	shooting;
	char			dead;
	char			curr_map;
	float			skyW;
	float			skyH;
	unsigned char	falling;
}					t_player;

typedef struct 		s_super_data
{
	int 			start_x;
	int 			end_x;
	t_sector		*sect;
	t_wall 			drawing_line;
	t_wall			wall;
	t_player 		player;
	int 			u0;
	int				u1;
	float 			scale_l;
	float 			scaleH;
	t_draw_data 	*data;
	SDL_Surface		*main_screen;
	SDL_Surface		*floor_texture;
	SDL_Surface		*ceil_texture;
}					t_super_data;

typedef struct		s_pr
{
	SDL_Surface		*texture;
	SDL_Surface		*background;
	SDL_Surface		*play_button;
	SDL_Surface		*exit_button;
	SDL_Surface		*logo;
	SDL_Surface		*choose_level_button;
	SDL_Rect		play_rect;
	SDL_Rect		exit_rect;
	SDL_Rect		logo_rect;
	SDL_Rect		choose_level_rect;
	SDL_Rect		font_rect;
	SDL_Color		font_color;
	TTF_Font		*font;
	char			**maps;
	int				sw;
	SDL_Event		event;
	int				i;
	int				maxi;
	int				win_h;
	int				win_w;
}					t_pr;

typedef struct		s_screen_inf
{
	int 			cya;
	int 			cyb;
	int 			ya;
	int 			yb;
	int				nya;
	int				nyb;
	int 			n_cya;
	int 			n_cyb;
	int				x;
	int 			end;
	int 			txtx;
	int				x_lenght;
	float			maxDist;
	int				z;
	float			dist;
	float			mapped;
	float			dx;
	float			scale_width_texture;
	t_vector		tex_pos;
	t_vector		vec;
}					t_screen_inf;

typedef struct		s_text_inf
{
	int				x;
	int				y1;
	int				y2;
	t_scaler		ty;
	unsigned		txtx;
	t_sector		*sect;
	SDL_Surface		*surface;
	SDL_Surface		*image;
	t_vector		tex_pos;
	float			scaleL;
	float			scaleH;
	t_light			**light_source;	
	float			brightness;

}					t_text_inf;

typedef struct		s_ceil_inf 
{
	SDL_Surface 	*dst;
	SDL_Surface 	*src;
	int 			x;
	int 			y;
	int 			end_y;
	float 			diff_height;
	t_player 		player;
	t_sector 		*sect;
	t_light 		**light_source;
	float			mapx;
	float			mapz;
	unsigned 		tx;
	unsigned		txtz;
	float			brightness;
}					t_ceil_inf;

typedef struct		s_world
{
	t_sector *sec;
	t_wall wall;
	t_player player;
	t_sdl *sdl;
	t_draw_data data;
	void*(*thread_draw_sector)(void*);
}					t_world;

typedef struct		s_rot
{
	t_sector *sec;
	t_wall wall;
	t_player player;
	t_sdl *sdl;
	t_draw_data data;
	t_wall line;
	void*(*thread_draw_sector)(void*);
}					t_rot;

typedef struct		s_proj
{
	t_sector		*sec;
	t_wall			wall;
	t_player		player;
	t_sdl			*sdl;
	t_draw_data		data;
	t_wall			line;
	int				u0;
	int				u1;
	float			scale_l;
	void*(*thread_draw_sector)(void*);
}					t_proj;

typedef struct		s_again
{
	t_sector		*sec;
	t_wall			wall;
	t_player		player;
	t_sdl			*sdl;
	t_draw_data		data;
}					t_again;

typedef struct		s_n
{
	t_player		player;
	t_wall			wall;
	t_wall			line;
	float			scale1;
	float			scale2;
}					t_n;

typedef struct		s_p_n_d
{
	t_player player;
	t_draw_data data;
}					t_p_n_d;

#define min(a,b)             (((a) < (b)) ? (a) : (b)) // min: Choose smaller of two scalars.
#define max(a,b)             (((a) > (b)) ? (a) : (b)) // max: Choose greater of two scalars.
#define clamp(a, mi, ma)      min(max(a,mi),ma)         // clamp: Clamp value into set range.
#define vxs(x0,y0, x1,y1)    ((x0)*(y1) - (x1)*(y0))   // vxs: Vector cross product
// Overlap:  Determine whether the two number ranges overlap.
#define Overlap(a0,a1,b0,b1) min(a0,a1) <= max(b0,b1) && min(b0,b1) <= max(a0,a1)
// IntersectBox: Determine whether two 2D-boxes intersect.
/*
#define IntersectBox(x0,y0, x1,y1, x2,y2, x3,y3) (Overlap(x0,x1,x2,x3) && Overlap(y0,y1,y2,y3))
// PointSide: Determine which side of a line the point is on. Return value: <0, =0 or >0.
#define PointSide(px,py, x0,y0, x1,y1) vxs((x1)-(x0), (y1)-(y0), (px)-(x0), (py)-(y0))
// Intersect: Calculate the point of intersection between two lines.
#define Intersect(x1,y1, x2,y2, x3,y3, x4,y4) ((t_vector) { \
    vxs(vxs(x1,y1, x2,y2), (x1)-(x2), vxs(x3,y3, x4,y4), (x3)-(x4)) / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)), \
    vxs(vxs(x1,y1, x2,y2), (y1)-(y2), vxs(x3,y3, x4,y4), (y3)-(y4)) / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)) })
*/

#define Yaw(y,z) (y + z * player.yaw)

void					run_with_buff(t_player *player, t_sdl *sdl, unsigned int win_x);
void					initialize_sdl_win(t_pr *m);
void					load_textures(t_pr *m, t_sdl *sdl, t_read_holder *holder);
SDL_Surface				*txt_surf(TTF_Font *font, char *text, SDL_Color color);
void					renderallshit(t_pr *m);
int						render_menu(t_pr *m, t_sdl *sdl);
int 					load_game(t_player *player, t_read_holder *holder);
int 					menu_hooks(t_pr *m, t_read_holder *holder);
SDL_Rect				change_size(SDL_Rect rect);
SDL_Rect				reset_size(SDL_Rect rect);
void 					free_menu(t_pr *menu);
void					apply_filter(SDL_Surface *surface, float intensity);
void					check_door(t_player *player, t_sector *sectors);
t_player				*new_t_player(int pos_x, int pos_y, t_point wid_size);
void					free_player(t_player *player);
void					move_player(t_player *player, float sin_angle, float cos_angle);
void					move_player_vertically(t_player *player);
void 					draw_scaled_image(SDL_Surface *screen, SDL_Surface *img, t_point pos, t_point size);
void 					load_guns(t_gun **gun);
void 					delete_guns(t_gun **all);
int 					scaler_next(t_scaler *i);
t_sector				*get_new_player_sector(t_vector player_pos, t_sector *intersect_sector);
void 					text_line(t_text_inf inf);
//void 					draw_world(t_sector *sec, t_wall wall, t_player player, t_sdl *sdl, t_draw_data data, void*(*thread_draw_sector)(void*));
void					draw_world(t_world);
void 					draw_floor_or_ceil(t_ceil_inf);
void					draw_enemy_sprite(t_item *obj, t_draw_data data, t_player player, SDL_Surface *surface);
void    				move_enemy_to_player(t_item *enemy, t_vector player_pos);
void					quicksort(t_item **headRef, t_player *player);
t_item					*quick_sort_recur(t_item *head, t_item *end, t_player *player);
t_item					*tail_of(t_item *cur);
t_vector				point_of_intersec(t_vector p1, t_vector p2, t_vector p3, t_vector p4);
float					side_of_a_point(t_vector p, t_vector s, t_vector end);
int						box_intersection(t_vector p1, t_vector p2, t_vector p3, t_vector p4);
t_scaler				init_scaler(int n, t_point curr, t_point dst);
void					make_intersect(t_wall *wall);
unsigned short			dot_inside_sector(t_vector player_pos, t_wall **walls, unsigned arr_size);
void					get_gun_to_player(t_player *player, enum e_gun_type gun_type, SDL_Surface *icon);
void					rest_of_the_action_shit(t_pr *m, Uint8 *menu, t_sdl *sdl, t_read_holder *holder);
void					draw_hud(t_sdl *sdl, t_player *player);
t_projectile			*create_projectile(t_player player);
void					delete_projectile(t_projectile **head, t_projectile *proj);
Uint8					move_projectile(t_projectile *proj);
void 					add_projectile(t_projectile **head, t_projectile *new);
void					draw_projectile(t_projectile *proj, t_draw_data data, t_player player, SDL_Surface *surface);
void					draw_projectiles(t_projectile **projectiles, t_p_n_d p, SDL_Surface *screen, t_item *items);
int						calc_floor_ceil(unsigned half_win_size_y, float floor_or_ceil_diff, float scale_y);
void 					draw_image(SDL_Surface *screen, SDL_Surface *img, t_point pos, t_point size);
void 					draw_image_with_criteria(SDL_Surface *screen, SDL_Surface *img, t_rect r, t_draw_data data);
void					delete_projectiles(t_projectile *head);
void 					list_light(t_light	**arr, unsigned arr_size);
void					draw_skybox(SDL_Surface *dst, t_point pos,int end_y, t_player player);
void					fill_super_data(t_super_data *super, t_sector *sec, t_draw_data *data, t_wall wall);
void 					fill_super_data_2(t_super_data *super,t_draw_data data, int step, int i);
void 					fill_super_data_3(t_super_data *super, t_sector *sec, t_player player, t_sdl *sdl);
void					draw_sectors(t_sector *sec, t_player *player, t_sdl *sdl, t_draw_data data);
void					map_wall_text(int *u0, int *u1, t_vector diff, float scaled_tex);
void					floor_and_ceil_calculation(t_draw_data *data, t_player player, t_wall line, t_vector scale);
void					neighbour_calculation(t_draw_data *data, t_n n);
t_screen_inf			fill_inf(t_super_data *super, t_wall cp);
void					calculate_frame(t_screen_inf *inf, t_wall cp, t_super_data *super);
void					calculate_neighbours(t_screen_inf *inf, t_wall cp, t_draw_data *data);
void					render_neighbours(t_screen_inf inf, t_super_data *super, t_wall cp);
void					find_tex_pos(t_screen_inf *inf, t_super_data *super);
void					draw_sectors(t_sector *sectors, t_player *player, t_sdl *sdl, t_draw_data data);
void					update_player(t_player *player, unsigned char move[4]);
int						hook_event(t_player *player, unsigned char move[4], t_sector *sectors);
void 					draw_sector_items(t_item **items, t_player *player, t_draw_data data, SDL_Surface *screen);
int						game_loop(t_sdl *sdl, t_player *player, t_sector *sectors);
void					*thread_draw_sector(void *param);
void					draw_sectors(t_sector *sec, t_player *player, t_sdl *sdl, t_draw_data data);
void 					free_data_holder(t_read_holder *holder);
#endif
